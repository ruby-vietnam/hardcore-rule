## Problem 1

```golang
func size(head *ListNode) int {
    if head == nil {
        return 0
    }
    return 1 + size(head.Next)
}

func middleNode(head *ListNode) *ListNode {
    index := size(head) / 2 + 1
    
    node := head
    for i := 1; i < index; i++ {
        node = node.Next
    }
    return node
}
```