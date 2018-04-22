## Problem 1 - [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/description/)

```go
func isIsomorphic(s string, t string) bool {
    if len(s) <= 1 {
        return true
    }
    
    m1, m2 := make(map[byte]byte), make(map[byte]byte)
    
    var tmp byte
    var ok bool
    for i := range s {
        if tmp, ok = m1[s[i]]; !ok {
            m1[s[i]] = t[i]
            if tmp, ok = m2[t[i]]; !ok {
                m2[t[i]] = s[i]
            } else if tmp != s[i] {
                return false
            }
        } else if tmp != t[i] {
            return false
        }
        
        if tmp, _ = m2[t[i]]; tmp != s[i] {
            return false
        }
    }
    
    return true
}
```

## Problem 2 - [Rotate List](https://leetcode.com/problems/rotate-list/description/)

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
    n, tail := getLen(head)
    if n <= 1 {
        return head
    }
    
    if k = k % n; k == 0 {
        return head
    }
    
    prev, node := getNode(head, n-k+1)
    
    tail.Next = head
    prev.Next = nil
    
    return node
}

func getLen(head *ListNode) (n int, tail *ListNode) {
    n = 0
    for head != nil {
        n++
        tail = head
        head = head.Next
    }
    
    return
}

func getNode(head *ListNode, k int) (prev, node *ListNode) {
    c := 0 
    
    prev, node = nil, head
    for head != nil {
        if c++;c == k {
            return    
        }
        
        prev = node
        node = node.Next
    }
    
    return
}
```

### Problem Bonus - [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/description/)

```go
func trap(height []int) (sum int) {
    if height == nil || len(height) <= 2 {
        return 0
    }
    
    n := len(height)
    
    h := make([]int, n)
    
    max := 0
    for i := n-1; i >= 0; i-- {
        if height[i] > max {
            max = height[i]
        }
        h[i] = max
    }
    
    max = 0 
    for i := 0; i < n; i++ {
        if height[i] > max {
            max = height[i]
        }
        
        if max > h[i] {
            sum += h[i] - height[i]
        } else {
            sum += max - height[i]
        }
    }
    
    return sum
}
```