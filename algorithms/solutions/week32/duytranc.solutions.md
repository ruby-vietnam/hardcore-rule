# Problem 1
#### [Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees/description/)
```cs
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
    public bool LeafSimilar(TreeNode root1, TreeNode root2) {
        var leafs1 = new List<int>();
        var leafs2 = new List<int>();
        
        dfs(root1, leafs1);
        dfs(root2, leafs2);
        
        if(leafs1.Count != leafs2.Count)
            return false;
        
        for(var i = 0 ; i < leafs1.Count ; i++){
            if(leafs1[i] != leafs2[i])
                return false;
        }
        
        return true;
    }
    
    private void dfs(TreeNode node, List<int> leafs){
        if(node.left == null && node.right == null){
            leafs.Add(node.val);
            return;
        } 
        if(node.left != null){
            dfs(node.left, leafs);
        }
        if(node.right != null){
            dfs(node.right, leafs);
        }
    }
}
```


