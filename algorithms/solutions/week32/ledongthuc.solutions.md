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

Problem 2:

https://leetcode.com/problems/most-frequent-subtree-sum/description/

```go
func findFrequentTreeSum(root *TreeNode) (result []int) {
    if root == nil {
        return result
    }
    
    frequentlySum := make(map[int]int)
    _, top := getSum(root, frequentlySum, math.MinInt32)
    for sum, frequently := range frequentlySum {
        if frequently == top {
            result = append(result, sum)
        }
    }
    return result
}

func getSum(node *TreeNode, sumMap map[int]int, top int) (sum int, newTop int) {
    if node == nil {
        return 0, top
    }
    
    stack := []*TreeNode {
        node,
    }
    for len(stack) != 0 {
        processing := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        
        sum += processing.Val
        if processing.Left != nil {
            leftSum, newTop := getSum(processing.Left, sumMap, top)
            sum += leftSum
            top = max(newTop, top)
        }
        if processing.Right != nil {
            rightSum, newTop := getSum(processing.Right, sumMap, top)
            sum += rightSum
            top = max(newTop, top)
        }
        sumMap[sum]++
        top = max(sumMap[sum], top)
    }
    
    return sum, top
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
```
