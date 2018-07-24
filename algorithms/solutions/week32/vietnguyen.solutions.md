# [Problem 1. Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees/description/)

```python 
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution:
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        # approach: list out the leaves of the two trees and then compare 
        # how to list the leaves? inorder traversal? 
        # don't need to save the leaves, keep two iterators to traverse the two trees together? 
        # want to avoid recursion, so we can keep two iterators 
        # idea: use DFS with stack to keep track of the traversal of two trees. 
        # with new node check if it's a leaf. 
        stack1 = []
        stack2 = []
        
        stack1.append(root1)
        stack2.append(root2)
        while len(stack1) > 0 and len(stack2) > 0: 
            # find the next leaf
            while (stack1[-1].left != None) or (stack1[-1].right != None):
                node1 = stack1.pop()
                if node1.left != None:
                    stack1.append(node1.left)
                if node1.right != None:
                    stack1.append(node1.right)
            nextLeaf1 = stack1.pop()
            
            while (stack2[-1].left != None) or (stack2[-1].right != None):
                node2 = stack2.pop()
                if node2.left != None:
                    stack2.append(node2.left)
                if node2.right != None:
                    stack2.append(node2.right)
            nextLeaf2 = stack2.pop()
            
            print(nextLeaf1.val, nextLeaf2.val)
            if nextLeaf1.val != nextLeaf2.val:
                return False 
            
        if len(stack1) > 0 or len(stack2) > 0: 
            return False 
        
        return True 
        
```

## [Problem 2. Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/description/)

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import defaultdict 

class Solution:
    
    def calcSubtreeSum(self, node):
        if node.left == None and node.right == None:
            self.countSum[node.val] += 1 
            return node.val 
        currentSum = node.val 
        if node.left != None:
            currentSum += self.calcSubtreeSum(node.left)
        if node.right != None: 
            currentSum += self.calcSubtreeSum(node.right)
        self.countSum[currentSum] += 1 
        return currentSum 
    
    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # idea: recursion function to find the subtree sum of each node while traversing the nodes 
        # need a class variable (a dictionary) to store the subtree sums. 
        # after traversing the tree, check the dictionary and find the most frequent subtree sum 
        
        if not root: 
            return [] 
        self.countSum = defaultdict(int)
        self.calcSubtreeSum(root)
        result = [] 
        current_max_subtree_sum = 0 
        for s in self.countSum:
            if self.countSum[s] > current_max_subtree_sum:
                result = [s]
                current_max_subtree_sum = self.countSum[s]
            elif self.countSum[s] == current_max_subtree_sum:
                result.append(s)
        return result
```
