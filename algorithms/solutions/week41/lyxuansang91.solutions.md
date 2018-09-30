# Week 41

## Problem 1 - [Single Number](https://leetcode.com/problems/single-number/description/)

```go
func singleNumber(nums []int) int {
    res := 0
    for i := range nums {
        res = res ^ nums[i]
    }
    return res
}
```