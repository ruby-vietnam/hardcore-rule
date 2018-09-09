## Problem 1: [Path Sum III](https://leetcode.com/problems/path-sum-iii/description/)

 ```java
 public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}
class Solution {
    int count = 0;

    private void countPathSum(TreeNode node, List<Integer> sumList, int sum) {
        if (node == null) {
            return;
        }
        int newLastSum = sumList.get(sumList.size() - 1) + node.val;
        sumList.add(newLastSum);
        int listSize = sumList.size();
        for (int i = 0; i < listSize - 1; i++) {
            if (newLastSum - sumList.get(i) == sum) {
                count++;
            }
        }
        countPathSum(node.left, sumList, sum);
        countPathSum(node.right, sumList, sum);
        sumList.remove(sumList.size() - 1);
    }

    public int pathSum(TreeNode root, int sum) {
        List<Integer> sumList = new ArrayList<>();
        sumList.add(0);
        countPathSum(root, sumList, sum);
        return count;
    }
}
```
## Problem 2: [Search 2d Matrix](https://leetcode.com/problems/search-a-2d-matrix-ii/description/)

 ```java
public static class Solution {
	public boolean searchMatrix(int[][] matrix, int target) {
    	for (int i = 0; i < matrix.length; i++) {
            if (matrix[i].length == 0 || matrix[i][0] > target) {
                return false;
            }
            int l = 0, r = matrix[i].length - 1;
            while (l <= r) {
                if (matrix[i][l] == target || matrix[i][r] == target) {
                    return true;
                }
                if (l >= r - 1) {
                    break;
                }
                int mid = (l + r) / 2;
                if (matrix[i][mid] > target) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
        }
        return false;
    }
}
```