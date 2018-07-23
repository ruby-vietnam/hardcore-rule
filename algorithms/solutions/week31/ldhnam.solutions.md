```java
class Solution {
    int max = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        help(root);
        return max;
    }

    private int help(TreeNode root) {
        if (root == null) return 0;
        int left = Math.max(0, help(root.left));
        int right = Math.max(0, help(root.right));
        max = Math.max(max, left + right + root.val);
        return root.val + Math.max(left, right);
    }
}
```