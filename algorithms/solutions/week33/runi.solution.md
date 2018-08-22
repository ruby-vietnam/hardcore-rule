## Problem 1
https://leetcode.com/problems/middle-of-the-linked-list/description/

```go
func middleNode(head *ListNode) *ListNode {
    fast := head

    for fast != nil && fast.Next != nil  {
        fast = fast.Next.Next
        head = head.Next
    }

    return head
}
```
