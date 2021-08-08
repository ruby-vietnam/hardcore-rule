# 141. Linked List Cycle

### Approach

[Wikipedia](https://en.wikipedia.org/wiki/Cycle_detection)

### Submission

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null)
            return false;

        ListNode slow = head;
        ListNode fast = head;

        while (slow.next != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (fast == null) return false;
            if (slow == fast) return true;
        }

        return true;
    }
}
```

### Submission detail

20 / 20 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 40 MB

# 160. Intersection of Two Linked Lists

### Approach

Let say, the list A and B and their tail is C.

So, our approach is very simple, we move step by step on the A and B. For each step, we check the current value, if they are the same, we return it. 
If one of two pointer reach to the end, we will swap and point it to opposite list.

So we have: `len(A) + len(C) + len(B) + len(C)` for `headA` pointer.

`len(B) + len(C) + len(A) + len(C)` for `headB` pointer.

And we can easily see they are the same. It means, at the end of this, `headA` and `headB` will point to the same Node.

### Submission

```java
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null)
            return null;

        ListNode ptrA = headA;
        ListNode ptrB = headB;
        while (ptrA != ptrB) {
            ptrA = ptrA != null ? ptrA.next : headB;
            ptrB = ptrB != null ? ptrB.next : headA;
        }

        return ptrA;
    }
}
```

### Submission detail

39 / 39 test cases passed.
	Status: Accepted
Runtime: 1 ms
Memory Usage: 41.9 MB

# 208. Implement Trie (Prefix Tree)

### Submission

```go
const ALPHABET_SIZE = 26
type Trie struct {
	Childrens [ALPHABET_SIZE]*Trie
	IsEndOfWord bool
}


/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{}
}


/** Inserts a word into the trie. */
func (this *Trie) Insert(word string)  {
	current := this
	for _, c := range word {
		index := c - 'a'
		if current.Childrens[index] == nil {
			current.Childrens[index] = &Trie{}
		}
		current = current.Childrens[index]
	}

	current.IsEndOfWord = true
}


/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	current := this
	for _, c := range word {
		index := c - 'a'
		if current.Childrens[index] == nil {
			return false
		}
		current = current.Childrens[index]
	}

	return current.IsEndOfWord
}


/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	current := this
	for _, c := range prefix {
		index := c - 'a'
		if current.Childrens[index] == nil {
			return false
		}

		current = current.Childrens[index]
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

### Submission detail

15 / 15 test cases passed.
Status: Accepted
Runtime: 108 ms
