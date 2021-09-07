# 1. Binary Tree Inorder Traversal

https://leetcode.com/problems/binary-tree-inorder-traversal

## 1.1. Summary

 - Recursively, go through the tree to collect values with priority:
	 - Left branch
	 - Current node
	 - Right branch

## 1.2. Code

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
    if root == nil {
        return nil
    }
    result := []int{}
    return inorderTraversalInternal(root, result)
}

func inorderTraversalInternal(item *TreeNode, result []int) []int {
    if item.Left != nil {
        result = inorderTraversalInternal(item.Left, result)
    }
    
    result = append(result, item.Val)
    
    if item.Right != nil {
        result = inorderTraversalInternal(item.Right, result)
    }
    
    return result
}
```

# 2. Same Tree

https://leetcode.com/problems/same-tree

## 2.2. Summary

 - Recursively, compare:
 	 - Current node's values
	 - Left branches
	 - Right branches

## 2.3. Code

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSameTree(p *TreeNode, q *TreeNode) bool {
	if p == nil && q == nil {
		return true
	}
	if p == nil || q == nil {
		return false
	}
	if p.Val != q.Val {
        return false
	}
	return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
}
```

# 3. Remove Duplicates from Sorted List II

https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

## 3.1. Summary

 - Use 2 pointers:
	 - Last is pointer that's before duplicated nodes.
	 - Current is pointer will be moved forward to continues checking.
 - If the pointer current.Next is same value with current, we loop until current.Next is differrent with current. It help to skip duplicated items. Last will link to new current.Next that's different with current.
 - If the pointer current.Next is NOT same value with current, move forward the Last because we surely current.Next is not duplicated of current.

## 3.2. Code

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    
    paddingHead := &ListNode{
        Val: 0,
        Next: head,
    }
    last := paddingHead
    current := head
    
    for current != nil {
        if current.Next != nil && current.Val == current.Next.Val {
            for current.Next != nil && current.Val == current.Next.Val {
                current = current.Next
            }
            last.Next = current.Next
        } else {
            last = last.Next
        }
        current = current.Next
    }

    return paddingHead.Next
}
```

