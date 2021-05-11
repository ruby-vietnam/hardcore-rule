# Week 5

## Problem 1
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

To find such pair, first, we select a node from the tree, then find other node that have value which equal to remaining value `rem = k - node.val`.

To find a second node, we start from the root, then depends on the target `rem` value to decide to stop, go left, or go right. We stop only when we found a node 
that has value equals to `rem` or we can not go further, then it means we can not find such node.

The first node in that pair can be any node, so we traverse to entire nodes in the tree, and check if we can found such pair with current node.

**Analysis**

Time complexity: O(nlogn) due to n times node traversing and logn for `check` function.

Complexity: O(n) for stack in `traverse` recursive.

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        # in-order traversal to all node
        # immediately return True if we found one such pair 
        def traverse(node):
            return node != None and (check(node) or traverse(node.left) or traverse(node.right))
        
        # check if this node can be paired with other node to form such k
        def check(node):
            rem = k - node.val
            # node's value must be strictly increasing 
            #  if remaining value is equal to this node then we can not find such pair
            if rem == node.val:
                return False
            
            # iteratively search for that node from the root
            node_iter = root
            while True:
                if rem < node_iter.val:
                    node_iter = node_iter.left
                else:
                    node_iter = node_iter.right
                # dead-end or we found that node
                if node_iter == None or rem == node_iter.val:
                    break
                    
            return node_iter != None
            
        
        return traverse(root)
```
```
422 / 422 test cases passed.
Status: Accepted
Runtime: 96 ms
Memory Usage: 16.4 MB
```
