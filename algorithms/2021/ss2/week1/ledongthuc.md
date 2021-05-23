# 1. Find the Town Judge

https://leetcode.com/problems/find-the-town-judge/

## 1.1. Summary

 Everybody in the town have two main attribute:
  - Attribute 1: the person voted someone else.
  - Attribute 2: Number of other person who vote to.

So bases on the requirement, the town judge is a person who have:
 - Attribute 1 = 0
 - Attribute 2 = total town people - 1 (except town judge)

```go
func findJudge(n int, trust [][]int) int {
    attr1 := make([]bool, n, n)
    attr2 := make([]int, n, n)
    for _, t := range trust {
        attr1[t[0] - 1] = true
        attr2[t[1] - 1]++
    }
    
    
    for index, trustSomeoneElse := range attr1 {
        if !trustSomeoneElse && attr2[index] == n -1 {
            return index + 1
        }
    }
    return -1
}
```


# 2. All Nodes Distance K in Binary Tree

https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

## 2.2. Summary

Let's split the big proble to smaller parts:
 - Find node `k` from target
 - Find target from root, then notice to target's parents:
 	- To detect if any target's parents match with node `k`
	- To find node `k-n` with another branches that doesn't contain target

 ![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/all-nodes-distance-k-in-binary-tree/all-nodes-distance-k-in-binary-tree.png)

 ```go
 /**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func distanceK(root *TreeNode, target *TreeNode, k int) []int {
    result := down(target, k)
    if k == 0 {
        return result
    }
    
    bubbleResult, _, _ := bubbleUp(root, target, k)
    return append(result, bubbleResult...)
}

func bubbleUp(node *TreeNode, target *TreeNode, k int) (result []int, upK int, found bool) {
    if node == nil {
        return []int{}, -1, false
    }
    
    if node == target {
        if k == 0 {
            result = append(result, node.Val)
        }
        return result, k - 1, true
    }
    
    leftResult, leftBubbleK, leftFound := bubbleUp(node.Left, target, k)
    rightResult, rightBubbleK, rightFound := bubbleUp(node.Right, target, k)
    
    if !leftFound && !rightFound {
        return []int{}, -1, false
    }
    
    if leftBubbleK == 0 || rightBubbleK == 0 {
        result = append(result, node.Val)
    }
    
    if leftFound {
        upK = leftBubbleK
        if node.Right != nil {
            result = append(result, down(node.Right, leftBubbleK - 1)...)
        }
    }
    
    if rightFound {
        upK = rightBubbleK
        if node.Left != nil {
            result = append(result, down(node.Left, rightBubbleK - 1)...)
        }
    }
    
    return append(append(result, leftResult...), rightResult...), upK - 1, leftFound || rightFound
}
    

func down(node *TreeNode, k int) ([]int) {
    if k < 0 {
        return []int{}
    }
    if k == 0 {
        return []int{node.Val}
    }
    
    result := make([]int, 0, k)
    if node.Left != nil {
        result = append(result, down(node.Left, k-1)...)
    }
    if node.Right != nil {
        result = append(result, down(node.Right, k-1)...)
    }
    return result
}
 ```
