## Problem 2

https://leetcode.com/problems/merge-two-binary-trees/description/

- Recursion ftw

```go
func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
	if t1 == nil {
		return t2
	}

	if t2 == nil {
		return t1
	}

	t3 := &TreeNode{
		Val: t1.Val + t2.Val,
	}

	t3.Left = mergeTrees(t1.Left, t2.Left)
	t3.Right = mergeTrees(t1.Right, t2.Right)
	return t3
}
```
