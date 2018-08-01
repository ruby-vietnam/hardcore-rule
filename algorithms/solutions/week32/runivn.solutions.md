## Problem 1
https://leetcode.com/problems/leaf-similar-trees/description/


```go

func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	s1 := dfs(root1)
	s2 := dfs(root2)

	if len(s1) != len(s2) {
		return false
	}

	for i, v := range s1 {
		if v != s2[i] {
			return false
		}
	}

	return true
}

func dfs(root *TreeNode) []int {
	var result []int
	if root.Left == nil && root.Right == nil {
		result = append(result, root.Val)
		return result
	}

	if root.Left != nil {
		result = append(result, dfs(root.Left)...)
	}

	if root.Right != nil {
		result = append(result, dfs(root.Right)...)
	}

	return result
}
```
