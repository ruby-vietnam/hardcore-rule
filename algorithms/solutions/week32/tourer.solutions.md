# Problem 2

## [Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/description/)
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
    private Map<Integer, Integer> counter;
    
    public int[] findFrequentTreeSum(TreeNode root) {
        counter = new HashMap<>();
        dfs(root);
        int countMax = 0;
        int max = 0;
        for(int key : counter.keySet()) {
            int val = counter.get(key);                   
            if(val > max) {
                max = val;
                countMax = 1;
            } else if(val == max) {
                countMax++;
            }
        }
        int[] res = new int[countMax];
        int index = 0;
        for(int key : counter.keySet()) {
            int val = counter.get(key);
            if(val == max) {
                res[index++] = key;
            } 
        }
        return res;
    }
    
    private int dfs(TreeNode node) {
        if(node == null) return 0;
        int sum = dfs(node.left) + dfs(node.right) + node.val;
        int count = 1;
        if(counter.containsKey(sum)) {
            count = counter.get(sum) + 1;
        }
        counter.put(sum, count);
        return sum;
    }
}
```
