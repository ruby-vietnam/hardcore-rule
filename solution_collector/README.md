# Solution collector

## Usage

- First, please make sure you have `GITHUB_TOKEN` as your environment variable.
- Find runable file in folder `prebuilt`

```
USAGE:
    soco <SUBCOMMAND>

FLAGS:
    -h, --help       Prints help information
    -V, --version    Prints version information

SUBCOMMANDS:
    help           Prints this message or the help of the given subcommand(s)
    merge
    preview
    week-report
```

Example:

Merge all PRs of week 38:
```
soco merge week38
```

Report week 32:
```
soco week-report week32
```

## Development

- Install Rust https://www.rust-lang.org/en-US/install.html
- Install Cargo https://doc.rust-lang.org/cargo/getting-started/installation.html
- Build:

```sh
cargo build --release
```
- Find your built in folder `target`
