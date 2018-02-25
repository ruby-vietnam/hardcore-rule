# Problem 1

```java
import java.util.*;

class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> max = new HashMap<>();
        Map<Integer, Boolean> mark = new HashMap<>();
        
        for (int i : nums) {
            mark.put(i, true);
            if (max.get(i) == null) { max.put(i, 1); }
            else { max.put(i, max.get(i)+1); }

            if (max.get(i-1) == null) { max.put(i-1, 1); }
            else { max.put(i-1, max.get(i-1)+1); }
        }

        System.out.println(max);
        int m = Integer.MIN_VALUE;
        for (Map.Entry<Integer, Boolean> entry : mark.entrySet()) {
            int k = entry.getKey();
            if (mark.get(k-1) != null || mark.get(k+1) != null) {
                int v = max.get(k);
                if (m < v) { m = v; }
            }
        };
        
        return m >= 0 ? m : 0;
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
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        TreeNode merge = new TreeNode(0);
        if (t1 == null && t2 == null) { return null; }
        if (t1 == null) return t2;
        if (t2 == null) return t1;
        
        merge.val = t1.val + t2.val;
        merge.left = mergeTrees(t1.left, t2.left);
        merge.right = mergeTrees(t1.right, t2.right);
        return merge;
    }
}
```

# Problem 3

```java
class Solution {
    public List<Integer> grayCode(int n) {
        if (n == 0) { 
            List<Integer> r = new ArrayList<>();
            r.add(0);
            return r;
        }        
        List<Integer> ret = grayCode(n-1);
        int msb = 1 << (n-1);
        int l = ret.size();        
        for (int i = l-1; i >= 0; i--) {
            ret.add((1 << (n-1)) + ret.get(i));
        }
        return ret;
    }
}
```
