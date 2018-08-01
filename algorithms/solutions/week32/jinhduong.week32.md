# #1 Leaf-Similar Trees 
``` csharp
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
    public bool LeafSimilar(TreeNode root1, TreeNode root2)
        {
            var leafs1 = new List<int>();
            var leafs2 = new List<int>();
            GetLeafs(root1, ref leafs1);
            GetLeafs(root2, ref leafs2);

            return leafs1.SequenceEqual(leafs2);
        }

        public void GetLeafs(TreeNode node, ref List<int> leafs)
        {   
            if (node == null) return;
            if (node.left == null && node.right == null)
                leafs.Add(node.val);

            if (node.left != null) GetLeafs(node.left, ref leafs);
            if (node.right != null) GetLeafs(node.right, ref leafs);
        }
}
```