### Prolem 1 - [Valid Anagram](https://leetcode.com/problems/valid-anagram/description/)

Status:
```
  ✔ Accepted
  ✔ 34/34 cases passed (5 ms)
```

```go
func isAnagram(s string, t string) bool {
    var counters = make([]int, 26) 
    if len(s) != len(t) {
        return false
    }
    n := len(s)
    for i := 0; i < n; i++ {
        counters[s[i]-'a']++
        counters[t[i]-'a']--
    }
    for i := 0; i < 26; i++ {
        if counters[i] != 0 {
            return false
        }
    }
    return true
}
```

### Problem 4 - [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

```
  ✔ Accepted
  ✔ 48/48 cases passed (12 ms)
```

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

import java.util.StringTokenizer;

public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder builder = new StringBuilder();
        bufferedSerialize(builder, root);
        return builder.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        StringTokenizer tokenizer = new StringTokenizer(data, " ");
        return bufferedDeserialize(tokenizer);
    }
    
    private void bufferedSerialize(StringBuilder builder, TreeNode root) {
        if (root == null) {
            builder.append("? ");
        } else {
            builder.append(root.val);
            builder.append(" ");
            bufferedSerialize(builder, root.left);
            bufferedSerialize(builder, root.right);
        }
    }
    
    private TreeNode bufferedDeserialize(StringTokenizer tokenizer) {
        if (!tokenizer.hasMoreTokens()) {
            return null;
        }
        
        String token = tokenizer.nextToken();
        if (token.equals("?")) {
            return null;
        }
        TreeNode root = new TreeNode(Integer.parseInt(token));
        root.left = bufferedDeserialize(tokenizer);
        root.right = bufferedDeserialize(tokenizer);
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```
