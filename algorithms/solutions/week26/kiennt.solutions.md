# Problem 2

```go
func levelOrder(root *TreeNode) [][]int {
    result := [][]int{}
    visit([]*TreeNode{ root }, &result)
    return result
}

func visit(nodes []*TreeNode, result *[][]int) {
    var nextNodes []*TreeNode
    var nextVal []int
    for _, node := range nodes {
        if node == nil {
            continue
        }
        nextVal = append(nextVal, node.Val)
        nextNodes = append(nextNodes, node.Left)
        nextNodes = append(nextNodes, node.Right)
    }
    if len(nextVal) > 0 {
        *result = append(*result, nextVal)
        visit(nextNodes, result)
    }
}
```