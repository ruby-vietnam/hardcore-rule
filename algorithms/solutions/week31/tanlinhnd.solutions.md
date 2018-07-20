# Problem 2: [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/description/)

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    max = -2147483648
    
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.dfs(root)
        return self.max
    
    def dfs(self, root):
        if root == None:
            return 0
        max_left, max_right = max(self.dfs(root.left), 0), max(self.dfs(root.right), 0)
        
        tmp = root.val + max_left + max_right
        if tmp > self.max:
            self.max = tmp
        return root.val + max(max_left, max_right)
```
