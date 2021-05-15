# Easy: Two Sum IV - Input is a BST

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

### Approach 1

Use a hash table to store the values of nodes in the tree. For each node `x`, if `k - x.val` equals to the value of a node we already traversed (called `y`), then we know there is a pair of nodes with sum equals to `k`.

```go
func findTarget(root *TreeNode, k int) bool {
	set := make(map[int]int)
	return findTargetRecursive(root, k, set)
}

func findTargetRecursive(root *TreeNode, k int, set map[int]int) bool {
	if root == nil {
		return false
	}
	if _, ok := set[k-root.Val]; ok {
		return true
	}
	set[root.Val] = 1
	return findTargetRecursive(root.Left, k, set) || findTargetRecursive(root.Right, k, set)
}
```

This approach traverses the tree with recursion. If we want to avoid too many recursion calls when the tree is large, we can use BFS for the traversal part.

### Approach 2

Similar to approach 1, we will still use a hash table to store values of nodes but we'll also have a queue (FIFO), to store nodes we will be visiting.

1. Put the root into the queue
2. While queue is not empty
	- pop a node `x` from the queue
	- if there is a node with value of `k - x.val` exists in hash table, return yes
	- otherwise, add `k - x.val` to the hash table
	- then, push `x.left` and `x.right` into the queue
3. Return false

```go
func findTarget(root *TreeNode, k int) bool {
	m := make(map[int]int)
	queue := make([]*TreeNode, 0)
	queue = append(queue, root)
	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]
		if _, ok := m[k-node.Val]; ok {
			return true
		}
		m[node.Val] = 1
		if node.Left != nil {
			queue = append(queue, node.Left)
		}
		if node.Right != nil {
			queue = append(queue, node.Right)
		}
	}
	return false
}
```

Time complexity: O(n), space complexity: O(n) for both approaches.

### Submission Detail

```
422 / 422 test cases passed.
Status: Accepted
Runtime: 24 ms
Memory Usage: 6.9 MB
```

# Medium: Path Sum III

https://leetcode.com/problems/path-sum-iii/

### Approach

There are 2 cases that we need to pay attention to:
1. The root node is included in a path
2. The root node is not included in a path

You can take a look at the example:

![leetcode example](https://assets.leetcode.com/uploads/2021/04/09/pathsum3-1-tree.jpg)

The root node of the tree, 10, is not included in any of the paths (2), but node 5 is included in 2 paths. Due to the nature of tree data structure, we can say 5 is the root node of a subtree of the bigger tree, and 5 itself is included when forming a path (1).

So, to find the number of paths, we need to find the number of paths in the tree where the root node is included, plus the number of paths in the tree where the root node is not included.

### The root node is included

In this case, since the root node is a part of a path, we now need to find *from the children of the root* the number of paths such that the sum of values equals `targetSum - root.value`. We can use recursion to find number of paths with remaining target sum for root's children - `root.left` and `root.right` respectively. When we reach a node where its value equals to the current targetSum, it means we have found a path and we will increase the count by one.

### The root node is not included

This case is simple, when the root node is not included, it means the number of paths in the tree at root node will equals to the number of paths in the root's left subtree plus the number of paths in the root's right subtree. This is a recursion pattern so we can just use recursion to solve it. When a node is null we will return 0, else keep using recursion to calculate down the tree.

### Code (Go)

```go
func pathSum(root *TreeNode, targetSum int) int {
	if root == nil {
		return 0
	}
	return pathSum(root.Left, targetSum) + pathSum(root.Right, targetSum) + pathSumIncludingRoot(root, targetSum)
}

func pathSumIncludingRoot(root *TreeNode, targetSum int) int {
	if root == nil {
		return 0
	}
	count := 0
	if root.Val == targetSum {
		count++
	}
	remainingSum := targetSum - root.Val
	count += pathSumIncludingRoot(root.Left, remainingSum) + pathSumIncludingRoot(root.Right, remainingSum)
	return count
}
```

Time complexity: O(n), space complexity: O(n).

### Submission Detail

```
126 / 126 test cases passed.
Status: Accepted
Runtime: 12 ms
Memory Usage: 4.4 MB
```
