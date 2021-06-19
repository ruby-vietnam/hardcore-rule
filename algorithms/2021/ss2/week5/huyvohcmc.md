# Easy: Number of Good Pairs

https://leetcode.com/problems/number-of-good-pairs/

### Approach

Build a hashmap to store the appearance of each number in the array. If a number `n` is not yet exists in the hashmap, assign `hashmap[n] = 1`. If we meet `n` again, increase counter of pairs to the value of `hashmap[n]`, and increase `hashmap[n]` to 1. This one is very similar to the two sum problem.

### Code

```go
func numIdenticalPairs(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	count := 0
	m := map[int]int{}
	for _, num := range nums {
		c, ok := m[num]
		if ok {
			count += c
			m[num] += 1
		} else {
			m[num] = 1
		}
	}
	return count
}
```

Time complexity: O(n), space complexity: O(n).

### Submission Detail

```
48 / 48 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.1 MB
```

# Medium: Partition Array for Maximum Sum

https://leetcode.com/problems/partition-array-for-maximum-sum/

### Approach

Traverse the array from index i = 1 to N (arr.length):
```
1. find the maximum element of the array up to index i-1 # maxElement
2. change `up to k` last elements of the subarray (index 0..i-1) to the value of maxElement:
  2.1. with each change, calculate the sum of the subarray at index i by adding the newly changed values with the largest sum of the subarray that not includes those newly changed values
  2.2. memorize the largest sum out of all the sums generated from step 2.1 into the memoization array
```

### Code

```go
func maxSumAfterPartitioning(arr []int, k int) int {
	N := len(arr)
	dp := make([]int, N+1)
	for i := 1; i <= N; i++ {
		maxElement, maxSum := 0, 0
		for j := 1; j <= k && i-j >= 0; j++ {
			maxElement = max(maxElement, arr[i-j])
			maxSum = max(maxSum, dp[i-j]+maxElement*j)
		}
		dp[i] = maxSum
	}
	return dp[N]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```

Time complexity: O(n*k), space complexity: O(n).

### Submission Detail

```
52 / 52 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 2.9 MB
```
