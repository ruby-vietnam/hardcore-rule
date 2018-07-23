package main

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxPathSum(root *TreeNode) int {
	res := math.MinInt64
	s := findMaxSum(root, &res)
	return max(res, s)
}

func findMaxSum(t *TreeNode, result *int) int {

	if t == nil {
		return 0
	}

	l := findMaxSum(t.Left, result)
	r := findMaxSum(t.Right, result)

	*result = max(*result, max(max(t.Val+l+r, t.Val+l), t.Val+r))

	return max(max(t.Val, t.Val+l), t.Val+r)
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func main() {

}
