## Problem 1

```golang
func dfs(node *TreeNode, result *[]int) {
	if node.Left == nil && node.Right == nil {
		*result = append(*result, node.Val)
		return
	}
	if node.Left != nil {
		dfs(node.Left, result)
	}
	if node.Right != nil {
		dfs(node.Right, result)
	}
}

func getLeaf(root *TreeNode) []int {
	result := []int{}
	dfs(root, &result)
	return result
}

func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	result1 := getLeaf(root1)
	result2 := getLeaf(root2)
	size1 := len(result1)
	size2 := len(result2)
	if size1 != size2 {
		return false
	}
	for i := 0; i < size1; i++ {
		if result1[i] != result2[i] {
			return false
		}
	}
	return true
}
```