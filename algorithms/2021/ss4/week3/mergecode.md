# 1. N-ary Tree Postorder Traversal
https://leetcode.com/problems/n-ary-tree-postorder-traversal/

## 1.1. Summary
- N-ary tree is multi-children of each parent node
- We push children by same direction into stack and then append node parent into res

## 1.2. Code

``` python
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if not root:
            return []
        
        s = [root]
        res = []

        while s:
            last = s.pop()

            res.append(last.val)

            s.extend(last.children or [])

        return res[::-1]
```

# 2.  N-ary Tree Preorder Traversal

https://leetcode.com/problems/n-ary-tree-preorder-traversal/

## 2.1. Summary

- This is reverse of postorder traversal


## 2.2. Code

```python

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if not root:
            return []
        
        res = []
        s = [root]
        
        while s:
            t = s.pop()
            
            res.append(t.val)
            s.extend(t.children[::-1] or [])
            
        return res

```

# 3. Binary Tree Level Order Traversal

https://leetcode.com/problems/binary-tree-level-order-traversal/

## 3.1. Summary
- Use BFS, traversal all childrent of current node and append into array

## 3.2. Code

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        
        s = [root]
        res = [[root.val]]
        
        while s:
            tmp = []
            
            for t in s:
                if t.left:
                    tmp.append(t.left)
                if t.right:
                    tmp.append(t.right)
            
            if tmp:
                res.append([x.val for x in tmp])
            
            s = tmp[:]
        
        return res                                   
```

# 4. Find Duplicate Subtrees

https://leetcode.com/problems/find-duplicate-subtrees/

## 4.1. Summary

- We create signature for each node, represented as its value and its children
- Same structure will have same signature

## 4.2. Code

```python
class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        from collections import defaultdict
        
        tree_path = defaultdict(int)
        
        if not root:
            return []
        
        res = []
        
        def dfs(node):
            if not node:
                return "*"
            
            path = "{}_{}_{}".format(str(node.val),dfs(node.left),dfs(node.right))
                        
            if tree_path[path] == 1:
                res.append(node)            

            tree_path[path] += 1
            
            return path
                
        dfs(root)
        
        return res
                
```
