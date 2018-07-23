# Problem 1

```rust
fn two_substring(x: &str) -> &str {
    if x.is_empty() || x.len() > 100_000 {
        return "NO";
    }
    let f1 = x.find("AB");
    let f2 = x.find("BA");
    if f1.is_none() || f2.is_none() {
        return "NO";
    }
    let x1 = f1.unwrap() as f32;
    let x2 = f2.unwrap() as f32;
    if (x1 - x2).abs() == 1 as f32 {
        return "NO";
    }
    "YES"
}
```
