# 653. Two Sum IV - Input is a BST

### Approach - BFS

The idea is maintaining a Set which keeps track the traversed nodes.
For each node we check whether its `val` is stored in the set. If YES, we can concluse that the node which has value `k - currentNode.val` was already traversed, then return `true`
If not, we add the value `k - currentNode.val` into the set, and then check its children left and right (BFS)

### Submission

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean findTarget(TreeNode root, int k) {
        return hasTarget(root, k, new HashSet<>());
    }
    
    private static boolean hasTarget(TreeNode root, int k, Set<Integer> s) {
        if (root == null) return false;
        
        if (s.contains(root.val)) 
            return true;
        else
            s.add(k - root.val);
        
        boolean hasTargetOnLeft = hasTarget(root.left, k, s);
        boolean hasTargetOnRight = hasTarget(root.right, k, s);
        
        return hasTargetOnLeft || hasTargetOnRight;
    }
}
```

### Submission detail

| Status   | Runtime     | Memory   | Language  |
| ---      | ----------- | -------- | --------- |
| Accepted | 3ms         | 40.3 MB  | java      |

### Analyze 

- Time complexity: O(n)
- Space complexity: O(n), the worst case is we have to fill all nodes into the set

# 437. Path Sum III

### Approach
We can easily have a conclusion that the fulfilled path is might contains the root node or not.
So,

`total = withRootPathSum + withoutRootPathSum`

In the first case - without the root node, the result is equal to `pathSum` of left node and the right node `total = pathSum(root.left, targetSum) + pathSum(root.right, targetSum)`

In the second case - the fullfilled path contains the root root, we have: `total = pathSumWithRoot(root.left, targetSum - root.val) + pathSumWithRoot(root.right, targetSum  - root.val)`

### Submission

```java
class Solution {
    public int pathSum(TreeNode root, int targetSum) {
        if (root == null)
            return 0;
        return pathSum(root.left, targetSum) + pathSum(root.right, targetSum) + pathSumWithRoot(root, targetSum);
    }

    private static int pathSumWithRoot(TreeNode root, int targetSum) {
        if (root == null)
            return 0;

        int r = 0;
        if (root.val == targetSum)
            r++;

        r += pathSumWithRoot(root.left, targetSum - root.val);
        r += pathSumWithRoot(root.right, targetSum - root.val);

        return r;
    }
}
```

### Submission detail

| Status   | Runtime     | Memory   | Language  |
| ---      | ----------- | -------- | --------- |
| Accepted | 23ms        | 40.2 MB  | java      |

### Analyze
- Time complexity: O(n^2)

