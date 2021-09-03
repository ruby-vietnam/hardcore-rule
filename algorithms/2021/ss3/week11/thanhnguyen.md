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
## Approach: Recursion
### 3.1 Solution
-

### 3.2 Code
```python
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
