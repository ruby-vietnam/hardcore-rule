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
## Problem 2
https://leetcode.com/problems/path-sum-iii/

### Brute Force
To find all paths that sum of all values along the path equals to the target sum, we can start from any node, and move to one of its child and so on, on each node, we check if the sum of all values so far equals to the target sum, then we increase the count to 1, we stop when there is no more path to go down from current node anymore.

We have to do that for all nodes in the tree (take each node as a starting node).

**Analysis**

Time complexity: each `check` function takes O(n) with n is number of nodes, and we traverse O(n) times so overall it should be O(n^2)).

Space complexity: O(n) for stack in recursive calls.

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        def check(node, s):
            if node == None:
                return 0
            
            # include this node to current sum
            s += node.val
            
            # count this path that ends at at this node if target sum is met.
            c = 1 if s == targetSum else 0

            return c + check(node.left, s) + check(node.right, s)
        
        def traverse(node):
            if node == None:
                return 0
            return check(node, 0) + traverse(node.left) + traverse(node.right)
    
        return traverse(root)
```
```

126 / 126 test cases passed.
Status: Accepted
Runtime: 840 ms
Memory Usage: 15.5 MB
```
### Improvement

Re-calculating sum of node's value along the path is time consuming and wasted, instead, if we can build some kind of memory about all of the possible values we can get if we go down from certain nodes, then we don't have to actually go down along the path anymore.

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        def build_insight(node):
            if node == None:
                return []
            l = build_insight(node.left)
            r = build_insight(node.right)
            mem[node] = [node.val + x for x in l+r] + [node.val]
            return mem[node]
            
        def count(node):
            if node == None:
                return 0
            c = len([x for x in mem[node] if x == targetSum])
            return c + count(node.left) + count(node.right)
            
        # mem store a mapping between node and list of its possible sum values 
        # from the node key to one of its child nodes.
        mem = {}
        build_insight(root)
        return count(root)
```
```
126 / 126 test cases passed.
Status: Accepted
Runtime: 328 ms
Memory Usage: 43.6 MB
```
