# Problem 1

```go
var memo []int

func robR(nums []int, i int) int {
    if i < 0 {
        return 0
    }
    if memo[i] >= 0 {
        return memo[i]
    }
    memo[i] = int(math.Max(float64(nums[i] + robR(nums, i - 2)), float64(robR(nums, i - 1))))
    return memo[i]
}

func rob(nums []int) int {
    memo = make([]int, len(nums))
    for i := range memo {
        memo[i] = -1
    }
    return robR(nums, len(nums) - 1)
}
```
