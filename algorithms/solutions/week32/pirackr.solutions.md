```python
class Solution:
    def findLeaf(self, n, node):
        if node.left:
            self.findLeaf(n, node.left)
        if node.right:
            self.findLeaf(n, node.right)
        if not node.left and not node.right:
            self.leafs[n].append(node.val)
            return
        else:
            return # If remove these two returns, speed will drop. Don't know why
    
    def leafSimilar(self, root1, root2):
        self.leafs = [[],[]]
        self.findLeaf(0, root1)
        self.findLeaf(1, root2)
        return self.leafs[0] == self.leafs[1]
```
