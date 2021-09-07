# Medium 1: Unique Binary Search Trees

https://leetcode.com/problems/unique-binary-search-trees/

### Code

```go
func numTrees(n int) int {
	dp := make([]int, n+1)
	dp[0] = 1
	dp[1] = 1

	for i := 2; i <= n; i++ {
		for j := 1; j <= i; j++ {
			dp[i] += dp[j-1] * dp[i-j]
		}
	}
	return dp[n]
}
```

### Submission Detail

```
19 / 19 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.1 MB
```

# Medium 2: Remove Duplicates from Sorted List II

https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

### Code

```go
func deleteDuplicates(head *ListNode) *ListNode {
	tmp := &ListNode{0, head}
	prev := tmp
	for head != nil {
		if head.Next != nil && head.Val == head.Next.Val {
			for head.Next != nil && head.Val == head.Next.Val {
				head = head.Next
			}
			prev.Next = head.Next
		} else {
			prev = prev.Next
		}
		head = head.Next
	}
	return tmp.Next
}
```

### Submission Detail

```
166 / 166 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 3.2 MB
```
