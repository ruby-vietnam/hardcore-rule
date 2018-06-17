## Problem 1

```go
func findTheDifference(s string, t string) byte {
    n := len(s)
    var ret byte = 0
    for i := 0; i < n; i++ {
        ret = ret ^ s[i] ^ t[i]
    }
    ret ^= t[n]
    return ret
}
```

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
func levelOrder(root *TreeNode) [][]int {
    return traverse(root, 0, [][]int{})
}

func traverse(root *TreeNode, depth int, result [][]int) [][]int {
    if root == nil {
        return result
    }
    if len(result) == depth {
        result = append(result, []int{})
    }
    result[depth] = append(result[depth], root.Val)
    result = traverse(root.Left, depth + 1, result)
    result = traverse(root.Right, depth + 1, result)
    return result
}
```
