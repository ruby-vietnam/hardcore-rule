### Problem 1: https://leetcode.com/problems/valid-palindrome-ii/

Time: 32ms

Complexity: O(n)

Solution is the same with Palindrome checking with some change.
When you got a invalid pair character, we have 2 cases, 
  1. the left one is removable character
  2. the right one is removable character

=> just loop over the string 2 twice and skip left/right removable character and make sure the string are a palindrome.
  
  
```go
func validPalindrome(s string) bool {
    if len(s) == 0 {
        return true
    }

    left, right, count := 0, len(s) - 1, 0
    for left < right && count <= 1 {
        if s[left] != s[right] {
            count++
            left++
        } else {
            left++
            right--
        }
    }

    if count < 2 {
        return true
    }

    left, right, count = 0, len(s) - 1, 0
    for left < right  && count <= 2 {
        if s[left] != s[right] {
            count++
            right--
        } else {
            left++
            right--
        }
    }

    return count < 2
}
```

### Problem 2:

Time: 8ms
Complexity: O(n)

Solution is using depth first search in binary tree. Main idea, we append right branch to end of left branch and move left branch (including new appended right branch) to right of node (replace current right branch).


![](https://preview.ibb.co/bVg5Vx/1.png)

Ex-cases:
 - If left of node don't have any branch, just keep the node
 - If right of node don't have any branch, move left branch to right of node.

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func flatten(root *TreeNode)  {
    if root == nil {
        return
    }
    
    DigAndAppend(root)
}

func  DigAndAppend(node *TreeNode) (*TreeNode) {
    if node.Left == nil && node.Right == nil {
        return node
    }
    
    if node.Left == nil && node.Right != nil {
        return DigAndAppend(node.Right)
    }
    
    lastLeft := DigAndAppend(node.Left)
    lastLeft.Right = node.Right
    node.Right = node.Left
    node.Left = nil
    if node.Right == nil {
        return lastLeft
    }
    return DigAndAppend(node.Right)
}
```
