# Problem 1

## [Path Sum III](https://leetcode.com/problems/path-sum-iii/description/)
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
    private int ways;
    
    public int pathSum(TreeNode root, int sum) {
        ways = 0;
        dfs(root, sum);
        return ways;
    }
    
    void dfs(TreeNode node, int target) {
        if(node == null) return;
        dfs2(node, target);
        dfs(node.left, target);
        dfs(node.right, target);
    }
    
    void dfs2(TreeNode node, int target) {
        if(node == null) return;
        if(node.val == target) ways++;
        dfs2(node.left, target - node.val);
        dfs2(node.right, target - node.val);
    }
}
```
