Problem 1:

https://leetcode.com/problems/isomorphic-strings

```go
func isIsomorphic(s string, t string) bool {
    if s == t {
        return true
    }
    if len(s) != len(t) {
        return false
    }
    
    checking := make(map[byte]byte)
    checking2 := make(map[byte]byte)
    for index, _ := range s {
        source := s[index]
        destination := t[index]
        
        checkingDestination, existed := checking[source];
        
        if !existed {
            checking[source] = destination
        } else if existed && destination != checkingDestination {
            return false
        }
        
        checkingSource, existed := checking2[destination];
        if !existed {
            checking2[destination] = source
        } else if existed && source != checkingSource {
            return false
        }
    }
    return true
}
```

Problem 2:

https://leetcode.com/problems/rotate-list

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
    if head == nil || head.Next == nil || k == 0 {
        return head
    }
    
    l :=[]*ListNode {head}
    tail := head
    length := 1
    
    for tail.Next != nil {
        length++
        l = append(l, tail.Next)
        tail = tail.Next
    }
    
    if length == k || (k%length == 0 && length < k) {
        return head
    } else if length < k {
        k = (k % length)
    }
    
    tail.Next = head
    l[length-k-1].Next = nil    
    return l[length-k]
}
```
