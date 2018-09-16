# [Problem 1. Path Sum III](https://leetcode.com/problems/path-sum-iii/description/)

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        self.totalPaths = 0 
        if root != None:
            self.traverse(root, sum)
        return self.totalPaths 
        
    def traverse(self, node, sum):
        if node == None:
            return
        
        print("Number of paths from node %d: %d" % (node.val,  self.numPathFromOneNode(node, sum)))
        self.totalPaths += self.numPathFromOneNode(node, sum)
        if node.left != None:
            self.traverse(node.left, sum)
        if node.right != None:
            self.traverse(node.right, sum)
        
        
    def numPathFromOneNode(self, root_start, sum_needed):
        res = 0 
        if root_start.val == sum_needed:
            res = 1
        if root_start.left != None:
            res = res + self.numPathFromOneNode(root_start.left, sum_needed - root_start.val)
        if root_start.right != None:
            res = res + self.numPathFromOneNode(root_start.right, sum_needed - root_start.val)
        return res 
```
