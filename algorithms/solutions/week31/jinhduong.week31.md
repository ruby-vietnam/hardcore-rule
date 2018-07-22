# #2 Binary Tree Maximum Path Sum
```csharp
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    int maxVal;
    public int MaxPathSum(TreeNode root)
    {
        maxVal = root.val;
        Helper(root);
        return maxVal;

    }

    private int Helper(TreeNode node)
    {
        if (node == null)
        {
            return 0;
        }

        int l = Math.Max(0, Helper(node.left));
        int r = Math.Max(0, Helper(node.right));
        maxVal = Math.Max(maxVal, l + r + node.val);
        return Math.Max(l, r) + node.val;
    }
}
```