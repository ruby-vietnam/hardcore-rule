# 1. Two Sum

## 1.1 Problem

https://leetcode.com/problems/two-sum/

## 1.2. Implement

```rust
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for i in 0..(nums.len() - 1) {
            for j in i+1..nums.len() {
                if nums[i] + nums[j] == target {
                    return vec![i as i32, j as i32]
                }
            }

        }
        return vec![]
    }
}

```

```text

54 / 54 test cases passed.
Status: Accepted
Runtime: 28 ms
Memory Usage: 2.2 MB

```

# 2. Generate Parentheses

## 2.1. Problem

https://leetcode.com/problems/generate-parentheses/

## 2.2. Implement

```rust
impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        fn back_track(s: String, open_count: i32, close_count: i32) -> Vec<String> {
            let mut res = vec![];
            if open_count == 0 && close_count == 0 {
                return vec![s];
            }

            if open_count > 0 {
                res.append(&mut back_track(s.clone() + "(", open_count - 1, close_count + 1));
            }

            if close_count > 0 {
                res.append(&mut back_track(s.clone() + ")", open_count, close_count - 1));
            }

            return res;
        }
        return back_track("".to_string(), n, 0)
    }
}

```

Result

```text
8 / 8 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.3 MB
```
