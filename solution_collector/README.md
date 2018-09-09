# Solution collector

First, please make sure you have `GITHUB_TOKEN` as your environment variable.

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
