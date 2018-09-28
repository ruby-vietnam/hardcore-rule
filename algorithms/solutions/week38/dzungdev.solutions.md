Problem1: https://leetcode.com/problems/path-sum-iii/description/

```java
public int pathSum(TreeNode root, int sum) {
        if (root == null) return 0;
        int rootPathCount = pathSumFromNode(root, sum, 0);
        int leftChildPathCount = pathSum(root.left, sum);
        int rightChildPathCount = pathSum(root.right, sum);
        return leftChildPathCount + rootPathCount + rightChildPathCount;
    }
    
    public int pathSumFromNode(TreeNode node, int sum, int parentSum) {
        if (node == null) return 0;
        int totalPath = 0;
        if (node.val + parentSum == sum) totalPath++;
        totalPath += pathSumFromNode(node.left, sum, node.val + parentSum);
        totalPath += pathSumFromNode(node.right, sum, node.val + parentSum);
        return totalPath;
    }
```

Problem2: https://leetcode.com/problems/search-a-2d-matrix-ii/description/

```java
public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length > 0 && matrix[0].length > 0) {
            int row = 0;
            int col = matrix[0].length -1;
            while (row < matrix.length && col >= 0) {
                if (matrix[row][col] == target) {
                    return true;
                } else if (matrix[row][col] > target) {
                    col--;
                } else {
                    row++;
                }
            }
        }
        return false;
    }
```
