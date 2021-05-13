## 653. Two Sum IV - Input is a BST

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

### First approach

For each node, node value is `x`, find a node in the tree that have value `(k-x)`. Find using binary search algorithm.

Time complexity: `O(nlogn)`

```
Runtime: 120 ms, faster than 15.00% of Python3 online submissions for Two Sum IV - Input is a BST.
Memory Usage: 20.7 MB, less than 7.98% of Python3 online submissions for Two Sum IV - Input is a BST.
```

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def solve(root, k):
    def check(node):
        if node is None:
            return False
        # print(f'Checking {node.val}')
        return binary_search(root, k - node.val, node.val) or check(node.left) or check(node.right)

    def binary_search(node, value, exclude):
        # if node is not None:
        #     print(f'Searching tree from {node.val} for value {value}, exclude {exclude}')
        if node is None:
            return False
        elif node.val == value and node.val != exclude:
            return True
        elif value < node.val:
            return binary_search(node.left, value, exclude)
        elif value > node.val:
            return binary_search(node.right, value, exclude)

    return check(root)

class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        return solve(root, k)
```

### Improvement

Store BST values in a `Set`, instead of doing binary search each time.

Time complexity: `O(n)` if `Set` lookup is `O(1)`

Time improved:

```
Runtime: 84 ms, faster than 52.53% of Python3 online submissions for Two Sum IV - Input is a BST.
Memory Usage: 21.1 MB, less than 7.97% of Python3 online submissions for Two Sum IV - Input is a BST.
```

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def solve(root, k):
    s = set()

    def add_to_set(node):
        if node is None:
            return
        s.add(node.val)
        if node.left is not None:
            add_to_set(node.left)
        if node.right is not None:
            add_to_set(node.right)

    def check(node):
        if root.left is None and root.right is None:
            return False
        if node is None:
            return False
        return ((node.val != k/2) and ((k - node.val) in s)) or check(node.left) or check(node.right)

    add_to_set(root)
    return check(root)

class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        return solve(root, k)
```
## 437. Path Sum III

https://leetcode.com/problems/path-sum-iii/

Use DFS to traverse tree, store all sums in the path to current node, called `sums` list. At each node, check the `sum[i] + node.val`, if that equals `targetSum`, record result.

Time complexity: `O(nlogn)`

```
Runtime: 524 ms, faster than 31.43% of Python3 online submissions for Path Sum III.
Memory Usage: 15.7 MB, less than 37.04% of Python3 online submissions for Path Sum III.
```

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def solve(root, target_sum):
    result = 0
    sums = []

    def visit(node):
        nonlocal result, sums

        if node is None:
            return

        for i in range(len(sums)):
            new_sum = sums[i] + node.val
            if new_sum == target_sum:
                result += 1
            sums[i] = new_sum
        sums.append(node.val)
        if node.val == target_sum:
            result += 1

        if node.left is not None:
            visit(node.left)
        if node.right is not None:
            visit(node.right)

        # Backtrack
        sums.pop()
        for i in range(len(sums)):
            sums[i] -= node.val

    visit(root)
    return result

class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        return solve(root, targetSum)
```
