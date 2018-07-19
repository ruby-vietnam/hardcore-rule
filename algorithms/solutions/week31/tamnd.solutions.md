## Problem 2

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxPathSum(root *TreeNode) int {
    res := root.Val
    val := traverse(root, &res)
    return max([]int{res, val})
}

func max(a []int) int {
    m := a[0]
    for _, v := range a {
        if v > m {
            m = v
        }
    }
    return m
}

func traverse(root *TreeNode, res *int) int {
    if root == nil {
        return 0
    }
    left := traverse(root.Left, res)
    right := traverse(root.Right, res)
    *res = max([]int{*res, root.Val + left + right, root.Val + left, root.Val + right})
    return max([]int{root.Val, root.Val + left, root.Val + right})
}
```
