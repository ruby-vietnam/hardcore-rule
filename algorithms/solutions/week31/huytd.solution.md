# Problem 1: Two Strings

http://codeforces.com/contest/550/problem/A

Don't laugh :v

```
use std::thread;

fn is_two_strings(input: &'static str) -> bool {
    let left_to_right = thread::spawn(move || {
        let s = format!("{}", input);
        let len = s.len();
        for start in 0..len {
            let end = start + 2;
            if end <= len {
                let pod: &str = &s[start..end];
                if pod == "AB" || pod == "BA" {
                    return start as i32;
                }
            }
        }
        -1i32
    });

    let right_to_left = thread::spawn(move || {
        let s = format!("{}", input);
        let len = s.len();
        for buf in 0..len {
            let start = len - buf;
            let end = start + 2;
            if end <= len {
                let pod: &str = &s[start..end];
                if pod == "AB" || pod == "BA" {
                    return start as i32;
                }
            }
        }
        -1i32
    });

    let left = left_to_right.join().unwrap();
    let right = right_to_left.join().unwrap();

    return left != right;
}

fn main() {
    let input = "IEWFIWABIWEFIWEFBAIWEFWEF";
    println!("{}", is_two_strings(input));
}
```
