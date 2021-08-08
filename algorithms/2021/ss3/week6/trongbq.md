# 1. Linked List Cycle
https://leetcode.com/problems/linked-list-cycle/

- Use fast and slow poiters to iterate through the list
- Because the list has a cycle, fast pointer will meet slow pointer eventually

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        slow, fast = head, head
        while fast != None and fast.next != None:
            slow, fast = slow.next, fast.next.next
            if slow == fast:
                return True
        return False
```
```
20 / 20 test cases passed.
Status: Accepted
Runtime: 48 ms
Memory Usage: 17.7 MB
```

# 4. Implement Trie (Prefix Tree)
https://leetcode.com/problems/implement-trie-prefix-tree/

```python
ALPHABET_SIZE = 26  # only lowercase English letters


class TrieNode:
    def __init__(self, char: Optional[str] = None, end: bool = False):
        self.val = char
        self.children = [None] * ALPHABET_SIZE
        self.end = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        node_iter = self.root
        for c in word:
            cidx = self.__index(c)
            if not node_iter.children[cidx]:
                node_iter.children[cidx] = TrieNode(c)
            node_iter = node_iter.children[cidx]
        node_iter.end = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        node_iter = self.root
        for c in word:
            cidx = self.__index(c)
            if not node_iter.children[cidx]:
                return False
            node_iter = node_iter.children[cidx]
        return node_iter.end

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        node_iter = self.root
        for c in prefix:
            cidx = self.__index(c)
            if not node_iter.children[cidx]:
                return False
            node_iter = node_iter.children[cidx]
        return True

    def __index(self, c):
        return ord(c) - ord('a')
```
```
15 / 15 test cases passed.
Status: Accepted
Runtime: 252 ms
Memory Usage: 33.8 MB
```
