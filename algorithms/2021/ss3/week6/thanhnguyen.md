# 1. (Easy) [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
## Approach 1:
### 1.1 Solution
-
---
- Time Complexity:
- Space Complexity:
### 1.2 Code
```
 /  test cases passed.
Status: Accepted
Runtime:  ms
Memory Usage:  MB
```

```python
```

# 2. (Easy) [160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)
## Approach 1:
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