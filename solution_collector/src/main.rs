extern crate serde_json;
extern crate github_rs;

use std::io::Error;
use std::fmt::Write;

use std::env;
use github_rs::client::{Github, Executor};
use serde_json::Value;

#[derive(Debug)]
enum Mode {
    Preview,
    Merge
}

fn main() -> Result<(), Box<Error>> {
    let token    = env::var("GITHUB_TOKEN").expect("GITHUB_TOKEN is not set");
    let owner    = env::var("OWNER").unwrap_or(String::from("ruby-vietnam"));
    let repo     = env::var("REPO").unwrap_or(String::from("hardcore-rule"));
    let mut args = env::args();
    args.next();
    let mode_str = args.next().unwrap_or(String::from("preview"));

    let mode = if mode_str == "merge" {
        Mode::Merge
    } else {
        Mode::Preview
    };
    println!("Running mode: {:?}", mode);

    let client = Github::new(token).expect("Invalid token");
    let (_, _, pulls)  = client.get()
        .repos()
        .owner(&owner)
        .repo(&repo)
        .pulls()
        .execute::<Value>().unwrap();

    for pull in pulls.unwrap().as_array().unwrap() {
        match mode {
            Mode::Preview => {
                let solved_str = pull["body"].as_str().unwrap();
                let mut summary = String::new();
                for line in solved_str.split("\r\n") {
                    if line.contains("Problem") {
                        summary.push_str(line);
                        summary.push_str(" | ");
                    }
                }
                write!(&mut summary, "Owner: {}", pull["user"]["login"].as_str().unwrap()).unwrap();
                println!("{}", summary);
            },
            Mode::Merge => {
                let number_str = pull["number"].as_u64().unwrap().to_string();
                let endpoint = format!("/repos/{}/{}/pulls/{}/merge", owner, repo, number_str);
                let result = client.put("")
                    .custom_endpoint(&endpoint)
                    .execute::<Value>().unwrap();
                println!("Merging {}. Result: {:?}", number_str, result);
            }
        }
    }

    // println!("Pulls: {:?}", pulls);
    return Ok(());
}
