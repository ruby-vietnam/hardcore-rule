# Easy 1: Linked List Cycle

https://leetcode.com/problems/linked-list-cycle/

### Approach

Use the "two pointers" technique, we can create two pointers called slow and fast, point them to the head node and start iterating the linked list. The slow pointer will travel one node at a time and the fast pointer will travel two nodes at a time. If the linked list is a cycle linked list, the fast pointer will catch up with the slow pointer eventually. If the linked list is not a cycle linked list, the fast pointer will reach the tail and becomes nil before the slow pointer.

### Code

```go
func hasCycle(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return false
	}
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
		if slow == fast {
			return true
		}
	}
	return false
}
```

Time complexity: O(n).

### Submission Detail

```
20 / 20 test cases passed.
Status: Accepted
Runtime: 5 ms
Memory Usage: 4.8 MB
```

# Medium 2: Implement Trie (Prefix Tree)

https://leetcode.com/problems/implement-trie-prefix-tree/

### Code

```go
type Trie struct {
	children  [26]*Trie
	endOfWord bool
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	current := this
	for _, char := range word {
		i := char - 'a'
		if current.children[i] == nil {
			current.children[i] = &Trie{}
		}
		current = current.children[i]
	}
	current.endOfWord = true
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	current := this
	for _, char := range word {
		i := char - 'a'
		if current.children[i] == nil {
			return false
		}
		current = current.children[i]
	}
	return current.endOfWord
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	current := this
	for _, char := range prefix {
		i := char - 'a'
		if current.children[i] == nil {
			return false
		}
		current = current.children[i]
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

### Submission Detail

```
15 / 15 test cases passed.
Status: Accepted
Runtime: 56 ms
Memory Usage: 18.1 MB
```
