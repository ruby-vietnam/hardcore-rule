# Problem 1

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
    public int pathSum(TreeNode root, int sum) {
        if (root == null) { return 0; }
        Map<Integer, Integer> prefix = new HashMap<>();
        prefix.put(0,1);
        return traverse(root, 0, sum, prefix);
    }
    
    private int traverse(TreeNode cur, int curSum, int targetSum, Map<Integer, Integer> prefix) {
        if (cur == null) { return 0; }
        curSum += cur.val;
        int path = prefix.getOrDefault(curSum - targetSum, 0);
        prefix.put(curSum, prefix.getOrDefault(curSum, 0) + 1);
        int res = path + traverse(cur.left, curSum, targetSum, prefix) +
                    traverse(cur.right, curSum, targetSum, prefix);
        prefix.put(curSum, prefix.get(curSum) - 1);
        return res;
    }
}
```
