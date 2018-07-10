# Problem 1: Min Max Sum

URL: https://www.hackerrank.com/challenges/mini-max-sum/problem

```rust
fn minmax_sum(input: &mut [i32]) -> Vec<i32> {
    input.sort_unstable();
    let n = input.len();
    let min = input[0..n-1].iter().fold(0, |sum, x| sum + x);
    let max = input[1..].iter().fold(0, |sum, x| sum + x);
    return vec![min, max];
}
```
