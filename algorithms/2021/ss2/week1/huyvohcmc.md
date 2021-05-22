# Easy: Find the Town Judge

https://leetcode.com/problems/find-the-town-judge/

### Approach

Make a count array of length N+1 in which `count[i]` indicates how many people trust person `i` minus how many people does `i` trust. If `count[i]` is 0, it means `i` trusts `x` people and `x` people trust `i`. If there is a judge in town, it means `count[judge]` is equivalent to N-1 (N-1 people trust the judge and the judge trusts no one). We can find the count of each person by a single iteration over the `trust` array.

### Code (Go)

```go
func findJudge(n int, trust [][]int) int {
	count := make([]int, n+1)
	for _, pair := range trust {
		count[pair[0]]--
		count[pair[1]]++
	}
	for i := 1; i <= n; i++ {
		if count[i] == n-1 {
			return i
		}
	}
	return -1
}
```

Time complexity: O(n), space complexity: O(n).

### Submission Detail

```
92 / 92 test cases passed.
Status: Accepted
Runtime: 100 ms
Memory Usage: 7.1 MB
```

# Medium: All Nodes Distance K in Binary Tree

https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

### Approach

Breadth-first search `k` times starting from the `target` node to find all nodes that have distance `k`. To include the parent node of a node during breadth-first search, build a hashmap `m` (using breadth-first search again) to store the parent node of each node in the tree.

For example, nodes that have distance 1 from a node `v` are:
- `v.left`
- `v.right`
- `m[v] // parent of v`

### Code (Go)

```go
func distanceK(root *TreeNode, target *TreeNode, k int) []int {
	if k == 0 {
		return []int{target.Val}
	}

	res := []int{}
	m := buildMap(root)
	queue := []*TreeNode{target}
	visited := make(map[*TreeNode]bool)
	depth := 0

	for len(queue) > 0 {
		l := len(queue)
		for i := 0; i < l; i++ {
			curr := queue[0]
			queue = queue[1:]
			if curr.Left != nil && !visited[curr.Left] {
				queue = append(queue, curr.Left)
			}
			if curr.Right != nil && !visited[curr.Right] {
				queue = append(queue, curr.Right)
			}
			if parent := m[curr]; parent != nil && !visited[parent] {
				queue = append(queue, parent)
			}
			visited[curr] = true
		}
		depth++
		if depth == k {
			for _, node := range queue {
				res = append(res, node.Val)
			}
			break
		}
	}

	return res
}

func buildMap(root *TreeNode) map[*TreeNode]*TreeNode {
	m := make(map[*TreeNode]*TreeNode)
	queue := []*TreeNode{root}

	for len(queue) > 0 {
		curr := queue[0]
		queue = queue[1:]
		if curr.Left != nil {
			m[curr.Left] = curr
			queue = append(queue, curr.Left)
		}
		if curr.Right != nil {
			m[curr.Right] = curr
			queue = append(queue, curr.Right)
		}
	}

	return m
}
```

Time complexity: O(n), space complexity: O(n).

### Submission Detail

```
57 / 57 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 3.4 MB
```
