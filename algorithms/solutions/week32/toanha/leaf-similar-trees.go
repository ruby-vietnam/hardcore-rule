package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	leafs1 := dfs(root1)
	leafs2 := dfs(root2)

	if len(leafs1) != len(leafs2) {
		return false
	}

	for i, v := range leafs1 {
		if v != leafs2[i] {
			return false
		}
	}

	return true

}

func dfs(node *TreeNode) []int {
	var result []int

	if node.Left != nil {
		result = append(result, dfs(node.Left)...)
	}

	if node.Right != nil {
		result = append(result, dfs(node.Right)...)
	}

	if node.Left == nil && node.Right == nil {
		result = append(result, node.Val)
	}

	return result
}

func main() {

}
