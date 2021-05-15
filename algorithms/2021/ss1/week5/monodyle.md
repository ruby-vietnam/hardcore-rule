# Two Sum IV - Input is a BST [Easy]

Problem: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

## Idea

I use a hashtable to save the values of the nodes in the BST.

Each time when we insert the value of a new node into the hashtable, we check if the hashtable contains `k - node.val`.

## Example

```go
func findTarget(root *TreeNode, k int) bool {
	m := make(map[int]int)
	var find func(node *TreeNode) bool
	find = func(node *TreeNode) bool {
		if node == nil {
			return false
		}
		if _, ok := m[k-node.Val]; ok {
			return ok
		}
		m[node.Val]++
		return find(node.Left) || find(node.Right)
	}
	return find(root)
}
```

## Submission Detail

```
422 / 422 test cases passed.
Status: Accepted
Runtime: 28 ms
Memory Usage: 7.3 MB
```

# Path Sum III [Medium]

Problem: https://leetcode.com/problems/path-sum-iii/

## Idea

I dont think... I do.

## Example

```go
func pathSum(root *TreeNode, targetSum int) int {
	if root == nil {
		return 0
	}
	var find func(node *TreeNode, sum int) int
	find = func(node *TreeNode, sum int) int {
		count := 0
		if node == nil {
			return 0
		}
		if node.Val == sum {
			count++
		}
		return count + find(node.Left, sum-node.Val) + find(node.Right, sum-node.Val)
	}
	return find(root, targetSum) + pathSum(root.Left, targetSum) + pathSum(root.Right, targetSum)
}
```

## Submission Detail

```
126 / 126 test cases passed.
Status: Accepted
Runtime: 16 ms
Memory Usage: 4.4 MB
```
