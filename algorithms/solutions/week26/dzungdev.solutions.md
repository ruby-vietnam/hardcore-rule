Problem1: https://leetcode.com/problems/find-the-difference/description/

We can use XOR for each character from both of strings, then after we XOR all character, the result is the different character we want to find.

Time complexity is O(n)
Space complexity is O(1)

```java
public char findTheDifference(String s, String t) {
        char c = t.charAt(t.length()-1);
        for (int i = 0; i < t.length() -1; i++) {
          c ^= t.charAt(i);
          c ^= s.charAt(i);
        }
        return c;
    }
```

Problem2: https://leetcode.com/problems/binary-tree-level-order-traversal/description/

We use BFS and for the level, we can get queue size to know how many element for the current level. 

Time complexity is: O(V)
Space complexity is: O(V)

```java
public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        List<List<Integer>> resultList = new ArrayList<>();
        if (root == null) {
          return resultList;
        }
        queue.add(root);
      while (!queue.isEmpty()) {
        int numOfNodeCurrentLevel = queue.size();
        List<Integer> subList = new ArrayList<>();
        for (int i = 0; i < numOfNodeCurrentLevel;i++) {
          TreeNode node = queue.poll();
          if (node.left != null) queue.add(node.left);
          if (node.right != null) queue.add(node.right);
          subList.add(node.val);
        }
        resultList.add(subList);
      }
      return resultList;
    }
```
