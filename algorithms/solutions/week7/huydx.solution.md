# Problem 1

```
import java.util.*;

class Solution {
    public int firstUniqChar(String s) {
        List<Character> cl = new ArrayList<>();
        Map<Character, Integer> cp = new HashMap<>();
        Map<Character, Integer> cm = new HashMap<>();
        char[] arr = s.toCharArray();
        int i = 0;
        for (char c : arr) {
            if (cm.get(c) != null) {
                cm.put(c, cm.get(c)+1);
            } else {
                cm.put(c, 1);
            }
            if (cm.get(c) == 2) {
                i++;
                cl.remove(new Character(c));
                continue;
            }
            if (cm.get(c) >= 3) {
                i++;
                continue;
            }
            cp.put(c, i);
            cl.add(c);
            i++;
        }

        if (cl.isEmpty()) { return -1; }
        return cp.get(cl.get(0));
    }
}
```

# Problem 2

```
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
    public boolean isSymmetric(TreeNode root) {
        if (root == null) { return true; }
        if (root.left == null && root.right != null) { return false; }
        if (root.left != null && root.right == null) { return false; }
        if (root.left == null && root.right == null) { return true; }
        return equal(root.left, root.right);
    }
    
    public boolean equal(TreeNode left, TreeNode right) {
        if (left == null) { return right == null; }
        if (right == null) { return left == null; }
        return left.val == right.val && equal(left.left, right.right) && equal(left.right, right.left);
    }
}
```
