## Problem 1 - [Valid Anagram](https://leetcode.com/problems/valid-anagram/description/)

```go
func isAnagram(s string, t string) bool {
    counter := make([]int, 256)
    mask := make([]uint64, 4)
    
    for i := range s {
        counter[s[i]]++
        mask[s[i] >> 6] |= 1 << (s[i] & 63)
    }
    
    for i := range t {
        if counter[t[i]]--; counter[t[i]] != 0 {
            mask[t[i] >> 6] |= 1 << (t[i] & 63)
        } else {
            mask[t[i] >> 6] &= ^(1 << (t[i] & 63))
        }
    }
    
    return mask[0] == 0 && mask[1] == 0 && mask[2] == 0 && mask[3] == 0
}
```

## Problem 3 - [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/description/)

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
    if lists == nil || len(lists) == 0 {
        return nil
    }
    
    k := len(lists)
    heap := make(Heap, k+1)
    
    for i := range lists {
        heap[i+1] = &HeapNode{
            lNode: lists[i],
            pos: i,
        }
        heap.up(i+1)
    }
    
    var head, tail, next *ListNode
    var top *HeapNode
    for {
        if top = heap[1]; top.lNode == nil {
            break            
        }
        
        next = top.lNode.Next
        head, tail = addNode(head, tail, top.lNode)

        heap[1].lNode, lists[top.pos] = next, next
        heap.down(k)
    }
    
    return head
}

type HeapNode struct {
    lNode *ListNode
    pos int
}

type Heap []*HeapNode

func (h Heap) up(child int) {
    for child > 1 && less(h[child], h[child >> 1]) {
        h.swap(child, child >> 1)
        child >>= 1
    }
}

func (h Heap) down(limit int) {
    child := 0
    for father := 1; father << 1 <= limit; {
        child = father << 1
        if child + 1 <= limit && less(h[child+1], h[child]) {
            child++
        }
        
        if less(h[child], h[father]) {
            h.swap(child, father)
            father = child
        } else {
            break
        }
    }
}

func (h Heap) swap(i, j int) {
    tmp := h[i]
    h[i] = h[j]
    h[j] = tmp
}

func less(a, b *HeapNode) bool {
    if a == nil {
        return false
    }
    if b == nil {
        return true
    }
    if a.lNode == nil {
        return false
    }
    if b.lNode == nil {
        return true
    }
    return a.lNode.Val < b.lNode.Val
}

func addNode(head, tail, node *ListNode) (*ListNode, *ListNode) {
    if head == nil {
        node.Next = nil
        return node, node
    }
    
    tail.Next, node.Next = node, nil
    tail = node
    
    return head, tail
}
```