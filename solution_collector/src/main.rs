extern crate serde_json;
extern crate github_rs;
extern crate regex;

use std::io::Error;
use std::fmt::Write;

use std::env;
use github_rs::client::{Github, Executor};
use serde_json::Value;
use regex::Regex;
use std::collections::HashMap;

#[derive(Debug)]
enum Mode {
    Preview,
    Merge
}

fn get_week(title: &str) -> u64 {
    let re = Regex::new(r"(?i)week\s*(\d+)").unwrap();
    if let Some(cap) = re.captures(title) {
        return cap.get(1).map_or(0, |w| w.as_str().parse::<u64>().unwrap_or(0));
    } else {
        return 0;
    }
}

fn print_report(client: Github, owner: String, repo: String) {
    let mut summaries: HashMap<u64, String> = HashMap::new();
    let mut page = 1;

    loop {
        let endpoint = format!("repos/{}/{}/pulls?page={}", owner, repo, page);
        println!("Fetching Page {}", page);

        let (_, _, pulls)  = client.get()
            .custom_endpoint(&endpoint)
            .execute::<Value>().unwrap();

        let pulls = pulls.unwrap();
        let pulls = pulls.as_array().unwrap();
        if pulls.len() == 0 { break }

        for pull in pulls {
            let solved_str = pull["body"].as_str().unwrap();
            if !solved_str.contains("Problem") {
                continue;
            }
            let week = get_week(pull["title"].as_str().unwrap());
            let mut summary = summaries.entry(week).or_insert(String::new());
            for line in solved_str.split("\r\n") {
                if line.contains("Problem") {
                    summary.push_str(line);
                    summary.push_str(" | ");
                }
            }
            write!(&mut summary, "Owner: {}\n", pull["user"]["login"].as_str().unwrap()).unwrap();
        }

        page += 1;
    }

    for (week, summary) in summaries.iter() {
        println!("Week {}: ", week);
        println!("{}", summary);
        println!("=========================");
    }
}

fn merge_pull_request(client: Github, owner: String, repo: String) {
    let mut page = 1;

    loop {
        let merged = false;
        let endpoint = format!("repos/{}/{}/pulls?page={}", owner, repo, page);
        println!("Fetching Page {}", page);

        let (_, _, pulls)  = client.get()
            .custom_endpoint(&endpoint)
            .execute::<Value>().unwrap();

        let pulls = pulls.unwrap();
        let pulls = pulls.as_array().unwrap();
        if pulls.len() == 0 { break }

        for pull in pulls.as_array().unwrap() {
            if !solved_str.contains("Problem") {
                continue;
            }
            let number_str = pull["number"].as_u64().unwrap().to_string();
            let endpoint = format!("repos/{}/{}/pulls/{}/merge", owner, repo, number_str);
            println!("Merging {}. Endpoint: {}", number_str, endpoint);

            let result = client.put("")
                .custom_endpoint(&endpoint)
                .execute::<Value>().unwrap();

            let merged = true;
            println!("Result: {:?}", result);
        }
        // There's no PR that can be merged from this page, move to next one
        if !merged {
            page += 1
        }
    }
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
    match mode {
        Mode::Preview => {
            print_report(client, owner, repo);
        },
        Mode::Merge => {
            merge_pull_request(client, owner, repo);
        }
    }
    // println!("Pulls: {:?}", pulls);
    return Ok(());
}
