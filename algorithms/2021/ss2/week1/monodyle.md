# Find the Town Judge [Easy]

Problem: https://leetcode.com/problems/find-the-town-judge/

## Example

```go
func findJudge(n int, trust [][]int) int {
	peoples := make([]int, n+1)
	trusted := make([]bool, n+1)
	for _, t := range trust {
		peoples[t[1]]++
		trusted[t[0]] = true
	}
	for i := 1; i <= n; i++ {
		if peoples[i] == n-1 && !trusted[i] {
			return i
		}
	}
	return -1
}
```

## Submission Detail

```
92 / 92 test cases passed.
Status: Accepted
Runtime: 136 ms
Memory Usage: 7.3 MB
```

# All Nodes Distance K in Binary Tree [Medium]

Problem: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

## Example

```go
func distanceK(root *TreeNode, target *TreeNode, k int) []int {
	parents := map[*TreeNode]*TreeNode{}

	var dfs func(root, parent *TreeNode)
	dfs = func(root, parent *TreeNode) {
		if root == nil {
			return
		}
		parents[root] = parent
		dfs(root.Left, root)
		dfs(root.Right, root)
	}
	dfs(root, nil)

	q := []*TreeNode{target}
	seen := map[*TreeNode]bool{}
	seen[target] = true
	var dist int
	var result []int = []int{}

	for len(q) > 0 {
		if dist == k {
			for _, v := range q {
				result = append(result, v.Val)
			}
			return result
		}
		l := len(q)
		for i := 0; i < l; i++ {
			if _, ok := seen[q[i].Left]; !ok && q[i].Left != nil {
				seen[q[i].Left] = true
				q = append(q, q[i].Left)
			}
			if _, ok := seen[q[i].Right]; !ok && q[i].Right != nil {
				seen[q[i].Right] = true
				q = append(q, q[i].Right)
			}
			if _, ok := seen[parents[q[i]]]; !ok && parents[q[i]] != nil {
				seen[parents[q[i]]] = true
				q = append(q, parents[q[i]])
			}
		}
		q = q[l:]
		dist++
	}

	return []int{}
}
```

## Submission Detail

```
57 / 57 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 3.3 MB
```
