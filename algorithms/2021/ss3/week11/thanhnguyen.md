# 1. (Ease) [94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
## Approach: Recursion
### 1.1 Solution
- Recursion inorder traversal the tree

### 1.2 Code
```python
class Solution:
    def inorderTraversal(self, root):
        results = []
        self.recursive_inorder_traversal(root, results)
        return results

    def recursive_inorder_traversal(self, root, results=None):
        """Recursive inorder traversal"""
        if root:
            # duyệt bên trái
            self.recursive_inorder_traversal(root.left, results)
            # duyệt gốc
            results.append(root.val)
            # duyệt bên phải
            self.recursive_inorder_traversal(root.right, results)
```

## Approach: Stack
### 1.1 Solution
- Use stack to save the node

### 1.2 Code
```python
class Solution:
    def inorderTraversal(self, root):
        results = []
        stack = []
        curr = root

        while (curr or len(stack) != 0):
            while curr:
                stack.append(curr)
                curr = curr.left

            curr = stack.pop()
            results.append(curr.val)
            curr = curr.right

        return results
```

# 2. (Ease) [100. Same Tree](https://leetcode.com/problems/same-tree/)
## Approach: Recursion
### 2.1 Solution
- Recursion check trees

### 2.2 Code
```python
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # both null tree
        if p is None and q is None:
            return True

        # one of tree null
        if p is None or q is None:
            return False

        # have 2 trees
        if p.val != q.val:
            return False
        else:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
```

# 3. (Medium) [96. Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)
## Approach:  Dynamic Programming 
### 3.1 Solution
n = 0 -> 0 node -> total = 1 tree
n = 1 -> 1 node -> total = 1 tree

n = 2 -> total = 2
(1)            (2)
    \   or    /
    (2)     (1)

n = 3 -> total = 2 + 1 + 2 = 5 trees
* Group: (1) at the root
    (1)              (1)             (1)
   /   \      =>        \               \      => group count = 2
 (_)   [2,3]            (2)     or      (3)
                           \           /
                            (3)      (2)
* Group: (2) at the root
    (2)              (2)
   /   \      =>     /  \                      => group count = 1
 [1]   [3]         (1)   (3)

* Group: (3) at the root
    (3)              (3)             (3)
   /   \      =>     /               /
 [1,2]  (_)        (1)     or      (2)         => group count = 2
                     \            /
                      (2)      (1)

=> Sub-problems => Dynamic Programming

*Formula*: Given [1,2,3, ... n]
- the Catalan numbers, called G(n)
- with the node at the root, call F(i, n).
For example: n = 3 => Find G(3)

- with 1 plant at the root => F(1, 3)
- with 2 plant at the root => F(2, 3)
- with 3 plant at the root => F(3, 3)

G(3) = F(1, 3) + F(2, 3) + F(3, 3)

And:
- with 1 plant at the root => F(1, 3)
    (1)
   /   \         => (_)   is the G(0)  => F(1, 3) = G(0) * G(2)
 (_)   [2,3]        [2,3] ís the G(2)

- with 2 plant at the root => F(2, 3)
    (2)
   /   \         => [1] is the G(1)  => F(2, 3) = G(1) * G(1)
 [1]   [3]          [3] ís the G(1)

- with 3 plant at the root => F(3, 3)
     (3)
   /    \         => [1, 2] is the G(2)  => F(3, 3) = G(2) * G(0)
 [1, 2] (_)          (_)    ís the G(0)

Summary:
                   ----- G(3) ------
                  /       |         \
                 /        |          \
                /         |           \
           F(1,3)       F(2,3)       F(3,3)        => F(i, n) = G(i-1) * G(n-i)
           / \           / \          / \
          /   \         /   \        /   \
       G(0) * G(2) + G(1) * G(1) + G(2) * G(0)


### 3.2 Code
```python
class Solution:
    def numTrees(self, n: int) -> int:
        if n in [0, 1]:
            return 1

        # table for cache
        numTree = [1] * (n + 1)
        # 0, 1 nodes have results is 1
        # do dynamic from 2
        for num_node in range(2, n + 1):
            total = 0

            # sum all F(i, num_node), i from 1 to num_node
            for i in range(1, num_node + 1):
                total += numTree[i - 1] * numTree[num_node - i]

            numTree[num_node] = total

        return numTree[n]
```


# 4. (Medium) [82. Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)
## Approach: Recursion
### 4.1 Solution
-

### 4.2 Code
```python
```

# 5. (Hard) [44. Wildcard Matching](https://leetcode.com/problems/wildcard-matching/)
## Approach: Recursion
### 5.1 Solution
-

### 5.2 Code
```python
```
