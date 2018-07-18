# Problem 1

## [Two Substrings](http://codeforces.com/contest/550/problem/A)
```java
class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        char[] a = in.next().toCharArray();
        if (found(a, "AB".toCharArray(), "BA".toCharArray()) || found(a, "BA".toCharArray(), "AB".toCharArray())) {
            out.println("YES");
        } else {
            out.println("NO");
        }
    }

    boolean found(char[] a, char[] first, char[] second) {
        boolean found = false;
        for (int i = 0; i < a.length - 1; i++) {
            if (!found && a[i] == first[0] && a[i + 1] == first[1]) {
                found = true;
                i++;
                continue;
            }
            if (found && a[i] == second[0] && a[i + 1] == second[1]) return true;
        }
        return false;
    }
}
```

# Problem 2
## [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/description/)
```java
class Solution {
    
    public int maxPathSum(TreeNode root) {
        Pair res = dfs(root);
        return Math.max(res.first, res.second);
    }
    
    private Pair dfs(TreeNode root) {
        if(root == null) {
            return null;
        }
        Pair left = dfs(root.left);
        Pair right = dfs(root.right);
        int max1, max2;
        if(left != null && right != null) {
            max1 = Math.max(0, Math.max(left.first, right.first)) + root.val;
            max2 = Math.max(Math.max(left.second, right.second), left.first + right.first + root.val);
        } else if(right == null && left == null) {
            return new Pair(root.val, root.val);
        } else if(right == null) {
            max1 = Math.max(0, left.first) + root.val;
            max2 = Math.max(left.second, left.first + root.val);
        } else {
            max1 = Math.max(0, right.first) + root.val;
            max2 = Math.max(right.second, right.first + root.val);
        }
        return new Pair(max1, Math.max(max1, max2));
    }
}

class Pair {
    int first;
    int second;
    
    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
```
