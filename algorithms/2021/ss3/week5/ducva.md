# 1. Excel Sheet Column Title

## Problem
https://leetcode.com/problems/excel-sheet-column-title

## Implement

```rust
impl Solution {
    pub fn convert_to_title(column_number: i32) -> String {
        // exception case
        if column_number == 0 {
            return "A".to_string();
        }
        let mut result = "".to_string();
        let mut value = column_number;
        let a_char = 'A' as u8;
        while value > 0 {
            let curr_index = ((value - 1) % 26) as u8;
            let curr_char = (a_char + curr_index) as char;
            result.insert(0, curr_char);
            value = (value - 1)/26;
        }
        result
    }
}
```

## Result
18 / 18 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2 MB


# 2. Climbing Stairs

## Problem
https://leetcode.com/problems/climbing-stairs/

## Solution

```rust

impl Solution {
    fn sub_problem(current_step: i32, target_step: i32, cache_result: &mut HashMap<String, i32>) -> i32 {
        if target_step <= current_step {
            return 0;
        }
        if target_step - current_step <= 1 {
            return 1;
        }
        if target_step - current_step <= 2 {
            return 2;
        }
        let key = format!("{}_{}", current_step, target_step);
        let val = cache_result.get(&key);
        if val.is_some() {
            return *val.unwrap();
        } else {
            let count_left = Solution::sub_problem(current_step + 1, target_step, cache_result);
            let count_right = Solution::sub_problem(current_step + 2, target_step, cache_result);
            let result = count_left + count_right;
            cache_result.insert(key,result);
            return result;
        }
    }

    pub fn climb_stairs(n: i32) -> i32 {
        let mut cache_result: HashMap<String, i32> = HashMap::new();
        return Self::sub_problem(0, n, &mut cache_result);
    }
}
```

## Result
45 / 45 test cases passed.
Status: Accepted
Runtime: 1 ms
Memory Usage: 2.1 MB


# 3. House robber

## Problem

https://leetcode.com/problems/house-robber/

## Implement

```python
from typing import List


class Solution:
    cache = None

    def rob(self, nums: List[int]) -> int:
        total_number = len(nums)
        if total_number == 0:
            return 0
        if self.cache is None:
            self.cache = [-1] * total_number

        self.cache[0] = nums[0]

        # more than 2 elements
        prev = self.cache[total_number - 1]
        if prev != -1:
            return prev

        if total_number == 2:
            result = max(nums[0], nums[1])
            self.cache[1] = result
            return result

        max_amt = 0
        for i in range(0, total_number - 1):
            amt = nums[i] + self.rob(nums[i + 2:])
            # print(f"i: {i}, amt: {amt}, max_amt: {max_amt}")
            if max_amt < amt:
                max_amt = amt
        self.cache[total_number - 1] = max_amt
        return max_amt
```

```text

68 / 68 test cases passed.
Status: Accepted
Runtime: 56 ms
Memory Usage: 14.4 MB

```
