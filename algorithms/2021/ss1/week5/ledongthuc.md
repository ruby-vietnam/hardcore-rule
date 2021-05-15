# 1. Two Sum IV - Input is a BST

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

## 1.1. Summary
 - To check any sum 2 nodes equal to `k`, we should walk through all nodes of tree.
	 - While walking through the tree, save node's value to a cache while walking through the tree
	 - While walking through the tree, check if any `remaining = k - node's value` available in the cache, then meeting the problem requirement

```go
func pathSum(root *TreeNode, targetSum int) int {
    return walk(root, targetSum, []int{})
}

func walk(node *TreeNode, targetSum int, branch []int) int {
    if node == nil {
        return 0
    }
    var counter int
    
    branch = append(branch, node.Val)
    var checkingSum int
    for i := len(branch) - 1; i >= 0; i-- {
        checkingSum+= branch[i]
        if checkingSum == targetSum {
            counter++
        }
    }
    return counter + walk(node.Left, targetSum, branch) + walk(node.Right, targetSum, branch)
}
```

## 1.2. Recursive reduction

 - Use a stack to reduce the recursion of tree walking
	 - Push children of a node to stack
	 - Loop until stack empty
	 - Pull from stack and compare with cached nodes values that their sum are `k`

```go
func pathSum(root *TreeNode, targetSum int) int {
    if root == nil {
        return  0
    }
    
    var totalMatches int
    s := stack{
        stackItem{root, []int{root.Val}},
    }
    
    for {
        if len(s) == 0 {
            return totalMatches
        }
        
        item := s.Pull()
        if item.node == nil {
            continue
        }
        node := item.node
        branch := item.branch
        
        var checkingSum int
        for i := len(branch) - 1; i >= 0; i-- {
            checkingSum+= branch[i]
            if checkingSum == targetSum {
                totalMatches++
            }
        }
        
        
        if node.Left != nil {
            leftBranch := make([]int, len(branch), len(branch))
            copy(leftBranch, branch)
            leftBranch = append(leftBranch, node.Left.Val)
            
            s.Push(stackItem{node.Left, leftBranch})
        }
        
        
        if node.Right != nil {
            rightBranch := make([]int, len(branch), len(branch))
            copy(rightBranch, branch)
            rightBranch = append(rightBranch, node.Right.Val)
            s.Push(stackItem{node.Right, rightBranch})
        }
    }
    return totalMatches
}


type stack []stackItem
type stackItem struct {
    node *TreeNode
    branch []int
}

func (s *stack) Push(n1 stackItem) {
    (*s) = append((*s), n1)
}

func (s *stack) Pull() (stackItem) {
    if len(*s) == 0 {
        return stackItem{}
    }
    
    result := (*s)[len(*s)-1]
    (*s) = (*s)[:len(*s)-1]
    return result
}
```

# 2.1. Path Sum III

https://leetcode.com/problems/path-sum-iii/

## 2.2. Summary

 - To count number of paths where the sum of the values along the path equals `k`, we go through all branches from root.
	 - Each branches from root, we walk from root to leave to build the branch.
	 - Each node are added to the branch while building, we can sum its value with parents sequence to count any new pathes that have their sum equals `k`

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/path-sum-iii/PathSumIII-branches.png)

```go
func pathSum(root *TreeNode, targetSum int) int {
    return walk(root, targetSum, []int{})
}

func walk(node *TreeNode, targetSum int, branch []int) int {
    if node == nil {
        return 0
    }
    var counter int
    
    branch = append(branch, node.Val)
    var checkingSum int
    for i := len(branch) - 1; i >= 0; i-- {
        checkingSum+= branch[i]
        if checkingSum == targetSum {
            counter++
        }
    }
    return counter + walk(node.Left, targetSum, branch) + walk(node.Right, targetSum, branch)
}
```

## 2.3. Recursive reduction

 - Use a stack to reduce the recursion of tree walking
	 - Push children of a node to stack
	 - Loop until stack empty
	 - Pull node from stack and run to check their sum branches value from root

```go
func findTarget(root *TreeNode, k int) bool {
    checking := map[int]struct{}{}
    s := stack{root}
    for {
        if len(s) == 0 {
            return false
        }
        
        node := s.Pull()
        if _, existed := checking[k - node.Val]; existed {
            return true
        }
        checking[node.Val] = struct{}{}
        s.Push(node.Left, node.Right)
    }
    return false
}

type stack []*TreeNode

func (s *stack) Push(n1, n2 *TreeNode) {
    if n1 != nil {
        (*s) = append((*s), n1)
    }
    if n2 != nil {
        (*s) = append((*s), n2)
    }
}

func (s *stack) Pull() (*TreeNode) {
    if len(*s) == 0 {
        return nil
    }
    
    result := (*s)[len(*s)-1]
    (*s) = (*s)[:len(*s)-1]
    return result
}
```
