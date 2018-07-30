Problem1: 

We can use DFS to scan all the leaf from left to right side and store the leaf to the list. Then compare 2 lists we will know it is similar leaf or not.

Time complexity is: O(n)
Space complexity is: O(n)

```java
public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> leafs1 = new ArrayList<>();
        List<Integer> leafs2 = new ArrayList<>();

        dfs(root1, leafs1);
        dfs(root2, leafs2);

        return leafs1.equals(leafs2);
    }

  private void dfs(TreeNode node, List<Integer> leafs) {
      if (node.left == null && node.right == null) leafs.add(node.val);
      if (node.left != null) dfs(node.left, leafs);
      if (node.right != null) dfs(node.right, leafs);

  }
```
