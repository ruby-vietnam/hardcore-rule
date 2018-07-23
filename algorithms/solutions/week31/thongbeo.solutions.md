#Problem 2
``` Java 
class Solution {
    int max;
    public int maxPathSum(TreeNode root) {
        max = Integer.MIN_VALUE;
        maxChildPathSum(root);
        return max;
    }
    
    private int maxChildPathSum(TreeNode node){
        if (node == null) 
            return 0;
        
        int sl = maxChildPathSum(node.left);
        int sr = maxChildPathSum(node.right); 
        
        max = Math.max(max, node.val + sl + sr);
        
        // when this node sum with child node < 0 -> skip node and use sum of child node.
        return Math.max(0, node.val + Math.max(sl, sr)); 
    }
}
```
