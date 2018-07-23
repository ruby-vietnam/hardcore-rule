Problem 1:

https://leetcode.com/problems/leaf-similar-trees/description/

```go
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
    return Equal(pickLeaf(root1), pickLeaf(root2) )
}

func pickLeaf(root *TreeNode) (result []int) {
    if root == nil {
        return result
    }
    
    stack := []*TreeNode {
        root,
    }
    for {
        if len(stack) == 0 {
            break
        }
        
        processing := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        if processing.Left == nil && processing.Right == nil {
            result = append(result, processing.Val)
            continue
        } 
        
         
        if processing.Right != nil {
            stack = append(stack, processing.Right)
        }
        if processing.Left != nil {
            stack = append(stack, processing.Left)
        }       
    }
    return result
}

func Equal(a, b []int) bool {
    if len(a) != len(b) {
        return false
    }
    for i, v := range a {
        if v != b[i] {
            return false
        }
    }
    return true
}
```
