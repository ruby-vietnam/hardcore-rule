# Medium: Kth Smallest Element in a BST

https://leetcode.com/problems/kth-smallest-element-in-a-bst/

### Code

```go
func kthSmallest(root *TreeNode, k int) int {
	stack := []*TreeNode{}
	curr := root
	for true {
		for curr != nil {
			stack = append(stack, curr)
			curr = curr.Left
		}
		curr = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		k -= 1
		if k == 0 {
			return curr.Val
		}
		curr = curr.Right
	}
	return -1
}
```

### Submission Detail

```
93 / 93 test cases passed.
Status: Accepted
Runtime: 22 ms
Memory Usage: 6.5 MB
```

# Medium: Construct Binary Tree from Preorder and Inorder Traversal

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

### Code

```go
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 || len(inorder) == 0 {
		return nil
	}
	rootVal := preorder[0]
	root := &TreeNode{Val: rootVal}
	i := 0
	for i < len(inorder) {
		if inorder[i] == rootVal {
			break
		}
		i++
	}
	root.Left = buildTree(preorder[1:i+1], inorder[:i])
	root.Right = buildTree(preorder[i+1:], inorder[i+1:])
	return root
}
```

### Submission Detail

```
203 / 203 test cases passed.
Status: Accepted
Runtime: 5 ms
Memory Usage: 4.5 MB
```
