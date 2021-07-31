# 1. Linked List Cycle

https://leetcode.com/problems/linked-list-cycle

## 1.1. Summary

- Create a fake node item that's used to detect the cycle list.
- Go through the list from the head. With the passed node, we assign the fake node item as their following link.
- Any node when checking has the next item is the fake node, which means we went through it already. The list cycles.

## 1.2. Code

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    if head == nil {
        return false
    }
    curr := head
    next := curr.Next
    
    checking := &ListNode{}
    
    for next != nil {
        curr.Next = checking
        if next == checking {
            return true
        }
        
        curr = next
        next = curr.Next
    }
    return false
}
```

# 2. Intersection of Two Linked Lists

https://leetcode.com/problems/intersection-of-two-linked-lists

## 2.1. Summary

- Intersection lists only merged right sides to cut off the right node to ensure they are the same length before comparing.
- After making two lists of the same length, use two pointers to check if they are the same node item sequence.

## 2.2. Code

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    if headA == nil || headB == nil {
        return nil
    }
    
    lA, lB := count(headA), count(headB)
    
    for lA > lB {
        headA = headA.Next
        lA--
    }
    for lA < lB {
        headB = headB.Next
        lB--
    }
    
    for headA != headB {
        if headA != nil {
            headA = headA.Next            
        }
        if headB != nil {
            headB = headB.Next            
        }
    }
    
    return headA
}

func count(node *ListNode) (i int) {
    for node != nil {
        i++
        node = node.Next
    }
    return i
}
```

# 3. Binary Search Tree Iterator

https://leetcode.com/problems/binary-search-tree-iterator

## 3.1. Summary

- Use stack to get all items of lists
- Sort array and store it internally as a stack
- HasNext() check if internal sorted stack's empty
- Next() pop the stack

## 3.2. Code

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type BSTIterator struct {
    inner []int
}

func Constructor(root *TreeNode) BSTIterator {
    inner := []int{}
    stack := []*TreeNode{root}
    for len(stack) > 0 {
        item := stack[len(stack) - 1]
        stack = stack[:len(stack)-1]
        inner = append(inner, item.Val)
        if item.Left != nil {
            stack = append(stack, item.Left)
        }
        if item.Right != nil {
            stack = append(stack, item.Right)
        }
    }
    sort.Ints(inner)
    return BSTIterator{inner}
}


func (this *BSTIterator) Next() int {
    r := this.inner[0]
    this.inner = this.inner[1:]
    return r
}


func (this *BSTIterator) HasNext() bool {
    return len(this.inner) > 0 
}


/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
```

# 4. Implement Trie (Prefix Tree)

https://leetcode.com/problems/implement-trie-prefix-tree

## 4.1. Summary

- Use tree to implement. Node's alias of a character of word. Words in a word presents by node's children.
- Each node has 2 important info:
	- Child nodes
	- Is it a word
- Insert: from root, check and create children nodes base on characters of the word, sequencely
- Search: from root, traversal to child nodes base on characters of the word.
	- If node of a character doesn't exist: word is not existed
	- If final node of final character isn't a word: word is not existed
- StartsWith: Same with Search, but doesn't check final node of final character. It's still valid if final node is not a full word

## 4.2. Code

```go
type TrieNode struct {
    childs map[rune]*TrieNode
    isWord bool
}

type Trie struct {
    root *TrieNode
}


/** Initialize your data structure here. */
func Constructor() Trie {
    return Trie {
        root: &TrieNode{
            childs: map[rune]*TrieNode{},
            isWord: false,
        },
    }
}


/** Inserts a word into the trie. */
func (this *Trie) Insert(word string)  {
    node := this.root
    for _, char := range word {
        if _, existed := node.childs[char]; !existed {
            node.childs[char] = &TrieNode{
                childs: map[rune]*TrieNode{},
                isWord: false,
            }
        }
        node = node.childs[char]
    }
    node.isWord = true
}


/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
    node := this.root
    for _, char := range word {
        if _, existed := node.childs[char]; !existed {
            return false
        }
        node = node.childs[char]
    }
    return node.isWord
}


/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
    node := this.root
    for _, char := range prefix {
        if _, existed := node.childs[char]; !existed {
            return false
        }
        node = node.childs[char]
    }
    return true
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
```
