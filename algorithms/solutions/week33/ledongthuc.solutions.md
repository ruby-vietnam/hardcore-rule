Solution 1:

https://leetcode.com/problems/middle-of-the-linked-list/description

```go
func middleNode(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    count,checking, middle  := 1, head, head
    for ;checking.Next != nil; checking = checking.Next {
        count++
        if count % 2 == 0 {
            middle = middle.Next
        }            
    }
    return middle
}
```
