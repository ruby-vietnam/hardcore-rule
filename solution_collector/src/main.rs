extern crate serde_json;
extern crate github_rs;

use std::io::Error;
use std::fmt::Write;

use std::env;
use github_rs::client::{Github, Executor};
use serde_json::Value;

enum Mode {
    Preview,
    Merge
}

fn main() -> Result<(), Box<Error>> {
    let token    = env::var("GITHUB_TOKEN").expect("GITHUB_TOKEN is not set");
    let owner    = env::var("OWNER").unwrap_or(String::from("ruby-vietnam"));
    let repo     = env::var("REPO").unwrap_or(String::from("hardcore-rule"));
    let mode_str = env::args().next().unwrap_or(String::from("preview"));

    let mode = if mode_str == "merge" {
        Mode::Merge
    } else {
        Mode::Preview
    };

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
                client.get()
                    .repos()
                    .owner(&owner)
                    .repo(&repo)
                    .pulls()
                    .number(pull["number"].as_str().unwrap())
                    .merge()
                    .execute::<Value>().unwrap();
            }
        }
    }

    // println!("Pulls: {:?}", pulls);
    return Ok(());
}
