#[macro_use]
extern crate serde_json;
#[macro_use]
extern crate structopt;
extern crate github_rs;
extern crate regex;
extern crate chrono;
extern crate base64;

use std::io::Error;
use std::fmt::Display;
use std::fmt;

use std::env;
use github_rs::StatusCode;
use github_rs::client::{Github, Executor};
use serde_json::Value;
use regex::Regex;
use std::collections::HashMap;
use structopt::StructOpt;

use chrono::DateTime;
use chrono::offset::Utc;

#[derive(StructOpt, Debug)]
#[structopt(name = "soco")]
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
struct Entry {
    title: String,
    done: bool
}

#[derive(Debug)]
struct WeekSubmitPR {
    week: u32,
    number: u32,
    owner: String,
    entries: Vec<Entry>,
    created_at: DateTime<Utc>,
}

impl Display for WeekSubmitPR {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "Owner: {:<20}. Entries: [", self.owner)?;
        for entry in self.entries.iter() {
            write!(f, "{}: ", entry.title)?;
            if entry.done {
                write!(f, "{:<2}", "X")?;
            } else {
                write!(f, "{:<2}", " ")?;
            }
        }
        write!(f, "]. At: {}", self.created_at)
    }
}

fn get_pull_requests(ctx: &Context) -> HashMap<u32, Vec<WeekSubmitPR>> {
    let mut summaries = HashMap::new();
    let mut page = 1;

    loop {
        let endpoint = format!("repos/{}/{}/pulls?page={}", ctx.owner, ctx.repo, page);

        let (_, _, pulls)  = ctx.client.get()
            .custom_endpoint(&endpoint)
            .execute::<Value>().unwrap();

        let pulls = pulls.unwrap();
        let pulls = pulls.as_array().unwrap();
        if pulls.len() == 0 { break }

        for pull in pulls.iter().filter_map(|pull| parse_pull_request(pull)) {
            let mut summary = summaries.entry(pull.week).or_insert(vec![]);
            summary.push(pull);
        }

        page += 1;
    }

    summaries
}

fn get_participants(ctx: &Context) -> Vec<String> {
    let endpoint = format!("repos/{}/{}/contents/algorithms/PARTICIPANTS.md", ctx.owner, ctx.repo);
    let (_, _, content)  = ctx.client.get()
        .custom_endpoint(&endpoint)
        .execute::<Value>().unwrap();

    let content = content.unwrap();
    let content = &content["content"].as_str().unwrap().replace("\n", "");
    let decoded = base64::decode(&content).unwrap();
    let content = String::from_utf8(decoded).unwrap();
    let mut result = vec![];
    let re = Regex::new(r"\-\s(\w+)").unwrap();

    for line in content.lines() {
        if let Some(cap) = re.captures(line) {
            result.push(cap.get(1).map(|name| name.as_str()).unwrap().to_owned());
        }
    }

    result
}

fn parse_week(title: &str) -> u32 {
    let re = Regex::new(r"(?i)week\s*(\d+)").unwrap();
    if let Some(cap) = re.captures(title) {
        return cap.get(1).map_or(0, |w| w.as_str().parse::<u32>().unwrap_or(0));
    } else {
        return 0;
    }
}

fn parse_entries(body_str: &str) -> Vec<Entry> {
    let re = Regex::new(r"(?i)\[.*\](.*)").unwrap();
    let re_check_done = Regex::new(r"\[.*[^\s].*\]").unwrap();
    body_str.lines().filter_map(|line| {
        if let Some(cap) = re.captures(line) {
            let title = cap.get(1).map_or(String::from(""), |m| m.as_str().trim().to_string());
            let done = if re_check_done.is_match(line) { true } else { false };
            Some(Entry { title, done })
        } else {
            None
        }
    }).collect()
}

/* Return score for an entry with the following rule:
 *  Problem 1 (Easy)   = 1
 *  Problem 2 (Medium) = 2
 *  Problem 3 (Hard)   = 4
 *  Problem 4 (Hard)   = 4
 */
fn parse_entry_score(entry: &Entry) -> u32 {
    if !entry.done { return 0; }
    let re = Regex::new(r"(\d)").unwrap();
    if let Some(cap) = re.captures(&entry.title) {
        let num = cap.get(1).map_or(0, |w| w.as_str().parse::<u32>().unwrap_or(0));
        return match num {
            3 | 4 => 4,
            _ => num
        };
    }
    return 0;
}

/* Sum up the total score for each PR here */
fn parse_submission_score(pr: &WeekSubmitPR) -> u32 {
    pr.entries.iter().fold(0u32, |acc, entry| acc + parse_entry_score(&entry))
}

fn parse_pull_request(pr: &Value) -> Option<WeekSubmitPR> {
    let body_str = pr["body"].as_str().unwrap();
    let re = Regex::new(r"\[.*\]").unwrap();
    if re.is_match(body_str) {
        let week = parse_week(pr["title"].as_str().unwrap());
        let owner = pr["user"]["login"].as_str().unwrap().to_string();
        let entries = parse_entries(body_str);
        let number = pr["number"].as_u64().unwrap() as u32;
        let created_at = pr["created_at"].as_str().unwrap().parse::<DateTime<Utc>>().unwrap();
        Some(WeekSubmitPR { week, owner, entries, number, created_at })
    } else {
        None
    }
}

fn week_report(ctx: Context, week: u32) {
    let mut summaries = get_pull_requests(&ctx);
    let mut non_participants = get_participants(&ctx);
    let mut participants: Vec<String> = vec![];
    let mut unregistered_participants: Vec<String> = vec![];

    for (parsing_week, summary) in summaries.iter_mut() {
        if *parsing_week == week {
            summary.sort_by_key(|pr| parse_submission_score(pr));
            for pr in summary.iter().rev() {
                if let Some(index) = non_participants.iter().position(|n| n == &pr.owner) {
                    non_participants.remove(index);
                    let score = parse_submission_score(&pr);
                    participants.push(format!("{} \t\t (score = {})", &pr.owner, score));
                } else {
                    unregistered_participants.push((&pr.owner).to_owned());
                }
            }
        }
    }

    let participants: Vec<String> = participants.iter().map(|p| format!(" - {}", p)).collect();
    let non_participants: Vec<String> = non_participants.iter().map(|p| format!(" - {}", p)).collect();
    let unregistered_participants: Vec<String> = unregistered_participants.iter().map(|p| format!(" - {}", p)).collect();

    println!("Submitted:\n{}\n", participants.join("\n"));
    println!("Did not submit:\n{}\n", non_participants.join("\n"));
    println!("Unregistered participants:\n{}\n", unregistered_participants.join("\n"));
}

fn preview(ctx: Context) {
    let mut summaries = get_pull_requests(&ctx);

    for (week, summary) in summaries.iter_mut() {
        println!("Week {}: ", week);
        summary.sort_by_key(|pr| pr.entries.iter().filter(|entry| entry.done).count());
        for pr in summary.iter().rev() {
            println!("{}", pr);
        }
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

        for pull in pulls.iter().filter_map(|pull| parse_pull_request(pull)) {
            if pull.week != week {
                continue;
            }
            let merge_endpoint = format!("repos/{}/{}/pulls/{}/merge", ctx.owner, ctx.repo, pull.number);
            println!("Merging {}. Endpoint: {}", pull.number, merge_endpoint);

            let body = json!({});
            let (_, result, response) = ctx.client.put(body)
                .custom_endpoint(&merge_endpoint)
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
            week_report(context, week);
        }
        Command::Merge { week } => {
            merge_pull_request(context, week);
        }
    }
    // println!("Pulls: {:?}", pulls);
    return Ok(());
}
