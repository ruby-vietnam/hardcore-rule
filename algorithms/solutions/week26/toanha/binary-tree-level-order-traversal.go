package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func appendAtLevel(root *TreeNode, arr [][]int, level int) [][]int {
	if root == nil {
		return arr
	}

	if len(arr) == level {
		arr = append(arr, []int{})
	}

	arr[level] = append(arr[level], root.Val)
	arr = appendAtLevel(root.Left, arr, level+1)

	return appendAtLevel(root.Right, arr, level+1)
}

func levelOrder(root *TreeNode) [][]int {
	return appendAtLevel(root, [][]int{}, 0)
}
