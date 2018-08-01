# Problem 1
Idea: leaf array == dfs and add leaf to a list

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    List<Integer> leaf1 = new ArrayList<>();
    List<Integer> leaf2 = new ArrayList<>();
    
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        dfs(root1, leaf1);
        dfs(root2, leaf2);
        return Arrays.equals(leaf1.toArray(), leaf2.toArray());
    }
    
    public void dfs(TreeNode node, List<Integer> leaf) {
        Stack<TreeNode> stack = new Stack<>();
        stack.push(node);
        while (!stack.isEmpty()) {
            TreeNode cur = stack.pop();
            if (cur.left != null) {
                stack.push(cur.left);
            }
            if (cur.right != null) {
                stack.push(cur.right);
            }
            if (cur.left == null && cur.right == null) { // leaf
                leaf.add(cur.val); 
            }
        }
    }
}
```
