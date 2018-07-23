# Problem 1

```java
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int minA = Integer.MAX_VALUE;
        int maxA = Integer.MIN_VALUE;
        int minB = Integer.MAX_VALUE;
        int maxB = Integer.MIN_VALUE;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == 'A' && i < s.length() - 1 && s.charAt(i + 1) == 'B') {
                if (i < minA) { minA = i; }
                if (i > maxA) { maxA = i; }
            }
            if (c == 'B' && i < s.length() - 1 && s.charAt(i + 1) == 'A') {
                if (i < minB) { minB = i; }
                if (i > maxB) { maxB = i; }
            }
        }

        if ((maxA != Integer.MIN_VALUE && minB != Integer.MAX_VALUE && maxA - minB >= 2) ||
            (maxB != Integer.MIN_VALUE && minA != Integer.MAX_VALUE && maxB - minA >= 2)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
```

# Problem 2

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
    int max;
    
    public int maxPathSum(TreeNode root) {
        max = Integer.MIN_VALUE;
        maxBottomDown(root);
        return max;
    }
    
    public int maxBottomDown(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int maxLeft = maxBottomDown(root.left);
        int maxRight = maxBottomDown(root.right);
        if (maxLeft < 0) { maxLeft = 0; }
        if (maxRight < 0) { maxRight = 0; }
        max = Math.max(max, maxLeft + maxRight + root.val);
        return Math.max(maxLeft, maxRight) + root.val;
    }
}
```
