
Problem 2:

https://leetcode.com/problems/binary-tree-maximum-path-sum/description/#

```go
func maxPathSum(root *TreeNode) int {
    m, response := calSum(root, math.MinInt64)
    return max(response, m)
}

func calSum(t *TreeNode, response int) (int, int) {
    if t == nil {
        return 0, response
    }
    
    left, response := calSum(t.Left, response)
    right, response := calSum(t.Right, response)
    
    return max(max(t.Val, t.Val+left), t.Val+right), max(response, max(max(t.Val+left+right, t.Val+left), t.Val+right))
}

func max(left, right int) int {
    if left > right {
        return left
    } else {
        return right
    }
}
```
