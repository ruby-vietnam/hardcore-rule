# Easy 2: Climbing Stairs

https://leetcode.com/problems/climbing-stairs/

### Approach

Base case:

- n == 0 -> ways = 0
- n == 1 -> ways = 1
- n == 2 -> ways = 2

Other:

With n >= 2, the total ways to reach `n`th step is the number of ways to reach `n-1`th step plus the number of ways to reach `n-2`th step:

- From `n-1`th step, there is 1 way to climb to `n`th step (step 1 step).
- From `n-2`th step, there is 2 ways to climb to `n`th step (step 2 steps once, or step 1 step twice).

By the pattern above, this problem is a fibonacci problem with n1 = 1 and n2 = 2.

### Code

```go
func climbStairs(n int) int {
	if n <= 2 {
		return n
	}
	steps := 0
	n1 := 1
	n2 := 2
	for i := 2; i < n; i++ {
		steps = n1 + n2
		n1 = n2
		n2 = steps
	}
	return steps
}
```

Time complexity: O(n).

### Submission Detail

```
45 / 45 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 1.9 MB
```

# Medium 1: House Robber

https://leetcode.com/problems/house-robber/

### Approach

This is another dynamic programming problem: we will create an array of maximum money (`dp`) we have robbed so far while looping through the input. `dp[0]` is the maximum money we can rob when there are `0` houses, `dp[1]` is the maximum money we can rob when there is `1` house, and `dp[nums.length]` will be the maximum money we can rob when there are `nums.length` houses. To calculate `dp[x]`, we compare `dp[x-1]` (maximum money until we meet the house at index `x`) with `dp[x-2]` + `nums[x]` (the money in the house at index `x`), and assign the bigger value for `dp[x]`.

### Code

```go
func rob(nums []int) int {
	numsLength := len(nums)
	if numsLength == 0 {
		return 0
	}
	dp := make([]int, numsLength+1)
	dp[0] = 0
	dp[1] = nums[0]
	for i := 1; i < numsLength; i++ {
		dp[i+1] = max(dp[i], dp[i-1]+nums[i])
	}
	return dp[numsLength]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```

Time complexity: O(n), space complexity: O(n).

### Submission Detail

```
68 / 68 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.1 MB
```
