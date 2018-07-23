#[macro_use]
extern crate serde_json;
#[macro_use]
extern crate structopt;
extern crate github_rs;
extern crate regex;

use std::io::Error;
use std::fmt::Write;

use std::env;
use github_rs::StatusCode;
use github_rs::client::{Github, Executor};
use serde_json::Value;
use regex::Regex;
use std::collections::HashMap;
use structopt::StructOpt;

#[derive(StructOpt, Debug)]
#[structopt(name = "solution_collector")]
struct Opt {
    #[structopt(subcommand)]
    command: Command
}

#[derive(StructOpt, Debug)]
enum Command {
    #[structopt(name = "preview")]
    Preview,
    #[structopt(name = "week-report")]
    WeekReport {
        week: u32
    },
    #[structopt(name = "merge")]
    Merge {
        week: u32,
    }
}

struct Context {
    owner: String,
    repo: String,
    client: Github
}

impl Context {
    fn new(token: String, owner: String, repo: String) -> Self {
        let client = Github::new(token).expect("Invalid token");
        Context {
            owner,
            repo,
            client
        }
    }
}

#[derive(Debug)]
struct Problem {
    title: String,
    done: bool
}

#[derive(Debug)]
struct SubmitEntry {
    week: u32,
    owner: String,
    problems: Vec<Problem>
}

fn get_week(title: &str) -> u32 {
    let re = Regex::new(r"(?i)week\s*(\d+)").unwrap();
    if let Some(cap) = re.captures(title) {
        return cap.get(1).map_or(0, |w| w.as_str().parse::<u32>().unwrap_or(0));
    } else {
        return 0;
    }
}

fn parse_problems(body_str: &str) -> Vec<Problem> {
    let re = Regex::new(r"(?i)\[.*\](.*)").unwrap();
    let re_check_done = Regex::new(r"\[.*[^\s].*\]").unwrap();
    body_str.lines().filter_map(|line| {
        if let Some(cap) = re.captures(line) {
            let title = cap.get(1).map_or(String::from(""), |m| m.as_str().to_string());
            let done = if re_check_done.is_match(line) { true } else { false };
            Some(Problem { title, done })
        } else {
            None
        }
    }).collect()
}

fn parse_pull_request(pr: Value) -> Option<SubmitEntry> {
    let body_str = pr["body"].as_str().unwrap();
    let re = Regex::new(r"(?i)Problem").unwrap();
    if re.is_match(body_str) {
        let week = get_week(pr["title"].as_str().unwrap());
        let owner = pr["user"]["login"].as_str().unwrap().to_string();
        let problems = parse_problems(body_str);
        Some(SubmitEntry { week, owner, problems })
    } else {
        None
    }
}

fn preview(ctx: Context) {
    let mut summaries: HashMap<u32, String> = HashMap::new();
    let mut page = 1;

    loop {
        let endpoint = format!("repos/{}/{}/pulls?page={}", ctx.owner, ctx.repo, page);
        println!("Fetching Page {}", page);

        let (_, _, pulls)  = ctx.client.get()
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
        print!("{}", summary);
        println!("=========================");
    }
}

fn merge_pull_request(ctx: Context, week: u32) {
    let mut page = 1;

    loop {
        let mut merged = false;
        let endpoint = format!("repos/{}/{}/pulls?page={}", ctx.owner, ctx.repo, page);
        println!("Fetching Page {}", page);

        let (_, _, pulls)  = ctx.client.get()
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
            let w = get_week(pull["title"].as_str().unwrap());
            if week != w {
                continue;
            }
            let number_str = pull["number"].as_u64().unwrap().to_string();
            let endpoint = format!("repos/{}/{}/pulls/{}/merge", ctx.owner, ctx.repo, number_str);
            println!("Merging {}. Endpoint: {}", number_str, endpoint);

            let body = json!({});
            let (_, result, response) = ctx.client.put(body)
                .custom_endpoint(&endpoint)
                .execute::<Value>().unwrap();

            if result == StatusCode::Ok {
                merged = true;
            }
            println!("Result: {:?}. Response: {}", result, response.unwrap_or(json!(null)));
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
    let opt = Opt::from_args();

    println!("Running opts: {:?}", opt);

    let context = Context::new(token, owner, repo);
    match opt.command {
        Command::Preview => {
            preview(context);
        },
        Command::WeekReport { week } => {

        }
        Command::Merge { week } => {
            merge_pull_request(context, week);
        }
    }
    // println!("Pulls: {:?}", pulls);
    return Ok(());
}
