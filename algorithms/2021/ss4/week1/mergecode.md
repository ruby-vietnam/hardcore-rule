# 1. Maximum Depth of Binary Tree
https://leetcode.com/problems/maximum-depth-of-binary-tree/

## 1.1. Summary

- Using recursive to solve this problem.

## 1.2. Code

``` python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def dfs(node):
            if not node:
                return 0
            
            l = dfs(node.left)
            r = dfs(node.right)
            
            max_depth = max(l,r)
            
            return max(l,r) + 1
        
        return dfs(root)
```

# 2. Convert Sorted Array to Binary Search Tree

https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

## 2.1. Summary

- Middle of array is root of tree

## 2.2. Code

```python

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def array_to_tree(l, r):
            if l > r:
                return
            
             mid = l + (r-l) // 2

            node = TreeNode(nums[mid])

            node.left = array_to_tree(l, mid-1)
            node.right = array_to_tree(mid+1, r)

        
        return array_to_tree(0, len(nums)-1)

```

# 3. Kth Smallest Element in a BST

https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/

- Because propery of in-order traversal, leftmost item is smaller than parent, so we count k elements in in-order traversal
- Early stopping when meet k-th

## 3.2. Code

```python
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        cnt, res = 0,0
        def dfs(node):
            nonlocal cnt,res
            if not node:
                return 

            dfs(node.left)

            cnt += 1

            if cnt == k:
                res = node.val

            dfs(node.right)

        dfs(root)

        return res
```

# 4.Construct Binary Tree from Preorder and Inorder Traversal 

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

## 4.1. Summary

- Preorder is produced parent node at first traversal (node, node.left, node.right)
- Inorder is produced leftmost node (node.left, node, node.right)
- So every node in preorder, we can divide inorder into two partitions: leftsubtree | node | rightsubtree
- Every node is unique so we can put index into hashmap for speeding up
- I see the solution after cannot implement it correctly :D

## 4.2. Code

```python
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder:
            return None
        
        curr_idx = 0
        hashmap = {num: idx for idx, num in enumerate(inorder)}

        def to_tree(l, r):
            if l > r:
                return
            
            nonlocal curr_idx

            root_value = preorder[curr_idx]

            curr_idx += 1

            root = TreeNode(root_value)
            
            root.left = to_tree(l, hashmap[root_value]-1)
            root.right = to_tree(hashmap[root_value]+1, r)

            return root
        
        return to_tree(0, len(preorder)-1)


```

# 5. Serialize and Deserialize Binary Tree

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/


## 5.1. Summary
- We store nodes and edges of tree
- Each node has unique id, edges will be src node to dest node

## 5.2 Code

```python
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return ""
        
        edges = {}
        nodes = {}
        cnt = 0
        
        def get_node_id(node):
            return node.__hash__()
        
        def dfs(node):
            
            if not node:
                return
            
            # Add to node pool
            nodes[get_node_id(node)] = node.val
            
            if node.left:
                edges["{}_{}_l".format(get_node_id(node),get_node_id(node.left))] = 1
                
            if node.right:
                edges["{}_{}_r".format(get_node_id(node),get_node_id(node.right))] = 1
                
            dfs(node.left)
            dfs(node.right)
        
        dfs(root)
        
        import json, gzip
        res = json.dumps(nodes) + "|||" + json.dumps(edges) + "|||" + str(get_node_id(root))
    
        
        return res
    
 

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        
        nodes_str, edges_str, root_str = data.split("|||")
        
        import json
        
        nodes = json.loads(nodes_str)
        edges = json.loads(edges_str)
        root_id = int(root_str)
        
        new_nodes = {}
        
        # Create nodes
        for node_id, node_val in nodes.items():
            new_nodes[int(node_id)] = TreeNode(node_val)
        
        for k in edges.keys():
            src, dst, o = k.split("_")
            src, dst = int(src), int(dst)
            
            if o == "l":
                new_nodes[src].left = new_nodes[dst]
            
            if o == "r":
                new_nodes[src].right = new_nodes[dst]
            
        return new_nodes[root_id]
```