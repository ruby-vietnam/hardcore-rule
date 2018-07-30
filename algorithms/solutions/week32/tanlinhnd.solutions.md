# Problem 1: [Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees/description/)

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
    var m, n []int
    dfs(root1, &m)
    dfs(root2, &n)
    
    if len(m) != len(n) {
        return false
    }
    
    for i, val := range m {
        if val != n[i] {
            return false
        }
    }
    return true
}

func dfs(root *TreeNode, leaf *([]int)) {
    if root == nil {
        return
    }
    if root.Left == nil && root.Right == nil {
        *leaf = append(*leaf, root.Val)
    }
    dfs(root.Left, leaf)
    dfs(root.Right, leaf)
}
```
