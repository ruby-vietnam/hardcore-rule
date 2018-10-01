# Problem 1
#### [Path Sum III](https://leetcode.com/problems/path-sum-iii/description/)
```cs
public class Solution {
    public int PathSum(TreeNode root, int sum) {
        
        return CountValidPathFromRoot(root, sum);
    }
    
     private int CountValidPathFromRoot(TreeNode node, int sum){
        if(node == null)
            return 0;
        
        var result = 0;
        result += DFS(node, 0, sum);
        result += CountValidPathFromRoot(node.left, sum);
        result += CountValidPathFromRoot(node.right, sum);
       
        return result;
    }
    
    private int DFS(TreeNode node, int rootSum, int expectedSum){
        if(node == null)
            return 0;
        
        var currentSum = rootSum + node.val;
        var result = 0;
        if(currentSum == expectedSum){
            result++;
        }
        result += DFS(node.left, currentSum, expectedSum);
        result += DFS(node.right, currentSum, expectedSum);
       
        return result;
    }
}
```