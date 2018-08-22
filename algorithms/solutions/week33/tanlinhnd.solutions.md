# Problem 1: [https://leetcode.com/problems/middle-of-the-linked-list/description/](Middle of the Linked List)

```go
func middleNode(head *ListNode) *ListNode {
    slow, fast := head, head
    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }
    return slow
}
```
