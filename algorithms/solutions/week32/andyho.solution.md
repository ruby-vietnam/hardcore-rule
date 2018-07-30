### Problem 1: https://leetcode.com/problems/leaf-similar-trees/description/

```Scala
object Solution {
    def leafList(root: TreeNode): List[Int] = {
        if (root == null) {
            List()
        } else if (root.left == null && root.right == null) {
            List(root.value)
        } else {
            leafList(root.left) ++ leafList(root.right)
        }
    }
    def leafSimilar(root1: TreeNode, root2: TreeNode): Boolean = {
        return leafList(root1) == leafList(root2)
    }
}
```
