# Problem 1
Just single loop from both side.
If meet char that not meet palindrome, we have 2 options: move 1 from left, or move 1 from right.
We first choose move 1 from left, and memoize backtrack index of move 1 from right.
If move 1 from left fail, back track to memoize index.

```java
class Solution {
    public boolean validPalindrome(String s) {
        assert(s.length() > 0);
        int i = 0;
        int j = s.length()-1;
        boolean isPalin = true;
        boolean skip = false;
        int backTrackI = -1;
        int backTrackJ = -1;
        
        while (true) {
            if (i >= j) { return true; }
            if (s.charAt(i) != s.charAt(j)) {
                if (skip) {
                    if (backTrackI != -1) { // have something to backTrack
                        i = backTrackI;
                        j = backTrackJ;
                        backTrackI = -1;
                        continue;
                    }
                    return false; 
                }
                if (s.charAt(i+1) == s.charAt(j)) {
                    if (s.charAt(i) == s.charAt(j-1)) {
                        backTrackI = i;
                        backTrackJ = j-1;
                    }
                    i++;
                    skip = true;
                    continue;
                } else if (s.charAt(i) == s.charAt(j-1)) {
                    skip = true;
                    j--;
                    continue;
                } else {
                    return false;
                }         
            } 
            
            i++;
            j--;
        }
    }
}
```

# Problem 2
Just pre-order loop

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
    public void flatten(TreeNode root) {
        if (root == null) { return; }
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode curr = root;
        while (curr != null || !stack.isEmpty()) {            
            if (curr.right != null) { // pre-order (left base)
                stack.push(curr.right);
            }
            
            if (curr.left != null) {
                curr.right = curr.left; //swap
                curr.left = null;
            } else {
                if (!stack.isEmpty()) {
                    TreeNode tmp = stack.pop();
                    curr.right = tmp;
                }
            }
            curr = curr.right;
        } 
    }
}
```

# Problem 3
This problem seems a bit wrong..
Just one pass loop to find every single char of s in t.
If found a char, increase index both.
If not found, increase index of t only until find next char of s.

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int is = 0;
        int it = 0;
        
        while (is <= s.length()-1 && it <= t.length()-1) {
            if (s.charAt(is) == t.charAt(it)) {
                is++;
                it++;
            } else {
                it++;   
            }
        }
        return is == s.length();
    }
}
```
