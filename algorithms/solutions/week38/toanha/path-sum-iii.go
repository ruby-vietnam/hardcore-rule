package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func pathSum(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}

	return dfs(root, sum) + pathSum(root.Left, sum) + pathSum(root.Right, sum)
}

func dfs(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}

	i := 0

	if root.Val == sum {
		i = 1
	}

	return i + dfs(root.Left, sum-root.Val) + dfs(root.Right, sum-root.Val)
}
