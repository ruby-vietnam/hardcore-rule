# Kth Smallest Element in a BST

https://leetcode.com/problems/kth-smallest-element-in-a-bst/

## Summary

 - In binary search tree, left node's value < parent node's value < right node's value.
 - So, if we want to find the k-th smallest element, we should start from left leaf of the tree and it's 1st smallest element ( k = 1 ) of binary search tree. We use depth first search to go to it.
 - From the 1st smallest element, we jump to parernt and understand it it's 2nd smallest element (k+1).
 - From 2nd smallest element, we go to right node and it's 3rd smallest element.
 - Apply same idea, we apply the depth first search and ranking smallest element with nested nodes to find k-th smallest element.

```
                                                               
                                 ┌─                            
                  depth        ┌─┘    ┌────────┐               
                  first      ┌─┘      │        │               
                  search   ┌─┘        │  4th   │               
                         ┌─┘          │        │               
                       ┌─┘            └────────┘               
                     ┌─┘                   │                   
                   ┌─┘      ┌──────────────┴──────────────┐    
                 ┌─┘        │                             │    
               ┌─┘     ┌────────┐                    ┌────────┐
             ┌─┘       │        │                    │        │
           ┌─┘         │  2nd   │                    │  5th   │
         ┌─┘           │        │                    │        │
       ┌─┘             └────────┘                    └────────┘
     ┌─┘                    │                                  
    ┌┘      ┌───────────────┴──────────────┐                   
   ┌┘       │                              │                   
  ┌┘   ┌────────┐                     ┌────────┐               
 ┌┘    │        │                     │        │               
┌┘     │  1st   │                     │  3rd   │               
▼      │        │                     │        │               
       └────────┘                     └────────┘               

```

## Code

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthSmallest(root *TreeNode, k int) int {
    counter := 0
    return depthFirstSearch(root, k, &counter)
}

func depthFirstSearch(node *TreeNode, k int, counter *int) int {
    if node == nil {
        return -1
    }
    
    result := -1
    if node.Left != nil {
        result = depthFirstSearch(node.Left, k, counter)
    }
    if result >= 0 {
        return result
    }
    
    (*counter)++
    if k == (*counter) {
        return node.Val
    }
    
    if node.Right != nil {
        result = depthFirstSearch(node.Right, k, counter)
    }
    return result
}

```
