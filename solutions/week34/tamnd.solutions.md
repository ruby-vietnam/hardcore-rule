## Problem 1

```go
func rob(nums []int) int {
    n := len(nums)
    if n == 0 {
        return 0
    }
    if n == 1 {
        return nums[0]
    }
    dp := make([]int, n)  
    dp[0] = nums[0];
    dp[1] = nums[1];
    for i := 2; i < n; i++ {
        if i-3 >= 0 { 
           dp[i] = max(dp[i-2] + nums[i],dp[i-3] + nums[i])
        } else { 
            dp[i] = dp[i-2] + nums[i]
        }

    }
    return max(dp[n-2],dp[n-1])
}

func max(a int, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}
```
