## Problem 2

```
var maxValue = -2147483648

func max(a int, b int) int {
    if (a > b) {
        return a
    }
    return b
}

func maxPathSum(root *TreeNode) int {
    maxRecursive(root);
    return maxValue;
}

func maxRecursive(root) int {
    if (root == nil) return 0
    sumLeft := max(maxPathSum(root.Left), 0)
    sumRight := max(maxPathSum(root.Right), 0)
    maxValue = max(maxValue )
    return root.Val + max(sumLeft, sum.Right)
}
```