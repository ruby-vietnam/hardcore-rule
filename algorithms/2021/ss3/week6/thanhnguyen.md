# 1. (Easy) [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
## Approach 1: Hash Table
### 1.1 Solution
- Use a set to save as hash table
- Go through the linked list, add value to the set
- If the next value exists in the set then it is linked list cycle
- If not, return False as final
---
- Time Complexity: O(n)
- Space Complexity: O(n)
### 1.2 Code
```
20 / 20 test cases passed.
Status: Accepted
Runtime: 56 ms
Memory Usage: 18.1 MB
```

```python
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        node_visited = set()

        while head is not None:
            if head in node_visited:
                return True

            node_visited.add(head)
            head = head.next

        return False
```

## Approach 2: Floyd's Cycle Finding Algorithm
### 1.1 Solution
- Use 2 pointer: slow pointer(step is 1), fast pointer(step is 2)
- If linked list cycle, then the fast pointer and slow pointer will meet together
- If not linked list then the fast pointer will reach the end first
---
- Time Complexity: O(n)
- Space Complexity: O(1)
### 1.2 Code
```
20 / 20 test cases passed.
Status: Accepted
Runtime: 52 ms
Memory Usage: 17.1 MB
```

```python
class Solution:
    def hasCycle(self, head: ListNode) -> bool:

        # case []
        if head is None:
            return False

        # 2 pointer
        slow = head
        fast = head.next

        # 2 pointer not meet together
        while slow != fast:
            # reach the end
            if fast is None or fast.next is None:
                return False

            # go ahead with its step
            slow = slow.next
            fast = fast.next.next

        # 2 pointer not meet together
        # cycle
        # slow == head
        return True
```

# 2. (Easy) [160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)
## Approach 1: An order list and retrieve value by index
### 1.1 Solution
-


### 1.1 Code
```python
```

# 3. (Medium) [173. Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/)
## Approach 1: Recursion with memorization

### 1.1 Solution
- Make a order list:
  - Use a list to retrieve and save BST in order. Because left always small than right then call left first, then right
  - If go to a leaf then return and append smallest number to the list
  - After go through the BST, we have a list in order
- Iterator:
  - Start with index is -1
  - When call next, increase index to 1 and select the value from order list within that index
  - When call hasNext, check if index + 1 in the range of the order list
### 1.2 Code

```
68 / 68 test cases passed.
Status: Accepted
Runtime: 32 ms
Memory Usage: 14.4 MB
```

```python
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.sorted_list = []

        self.index = -1

        self.in_order(root)

    def in_order(self, root):
        if not root:
            return
        self.in_order(root.left)
        self.sorted_list.append(root.val)
        self.in_order(root.right)

    def next(self) -> int:
        self.index += 1
        return self.sorted_list[self.index]

    def hasNext(self) -> bool:
        return self.index + 1 < len(self.sorted_list)

```

# 4. (Medium) [208. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)
## Approach 1:
### 1.1 Solution

### 1.2 Code

```
 /  test cases passed.
Status: Accepted
Runtime:  ms
Memory Usage:  MB
```

```python
```

# 4. (Hard) [224. Basic Calculator](https://leetcode.com/problems/basic-calculator/)
## Approach 1:
### 1.1 Solution

### 1.2 Code

```
 /  test cases passed.
Status: Accepted
Runtime:  ms
Memory Usage:  MB
```

```python
```