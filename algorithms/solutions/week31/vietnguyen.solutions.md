## [Problem 1: Two substrings](http://codeforces.com/contest/550/problem/A)

```python 
if __name__ == "__main__":
    s = input()
    # brute force: find AB, then find BA in the rest of the string --> O(N^2)
    # better: find the first AB from the left, the first BA from the right. Then compare index of these two.
    # also need to find the first BA from the left and the first AB from the right. 
    first_AB_index = -1
    first_BA_index = -1
    last_AB_index = -1
    last_BA_index = -1
    
    for i in range(len(s) - 1):
        if s[i:i+2] == 'AB':
            first_AB_index = i
            break

    for i in range(len(s) - 1):
        if s[i:i+2] == "BA":
            first_BA_index = i
            break

    for i in range(len(s)-1,-1,-1):
        if s[i:i+2] == "AB":
            last_AB_index = i
            break

    for i in range(len(s)-1,-1,-1):
        if s[i:i+2] == "BA":
            last_BA_index = i
            break

    if first_AB_index == -1 or first_BA_index == -1:
        print("NO")
        
    elif first_AB_index +2 <= last_BA_index or first_BA_index + 2 <= last_AB_index:
        print("YES")
    else:
        print("NO")

```

## [Problem 2: Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/description/)

```python
  # Definition for a binary tree node.
  # class TreeNode:
  #     def __init__(self, x):
  #         self.val = x
  #         self.left = None
  #         self.right = None

  class Solution:
      
      def maxPathSum(self, root):
          """
          :type root: TreeNode
          :rtype: int
          """
          self.current_max_sum = root.val
          self.helper(root)
          return self.current_max_sum 
        
      # this recursive function finds the max path sum of all the paths that go through `node` and have `node` as the topmost node in the tree. 
      def helper(self, node):
          res = 0 
          if node == None: 
              return 0 
          maxPathSumLeft = self.helper(node.left)
          maxPathSumRight = self.helper(node.right)
          res = max(node.val, node.val + maxPathSumLeft, node.val + maxPathSumRight, node.val + maxPathSumLeft + maxPathSumRight)
          # need to update current_max_sum if found any larger value 
          if res > self.current_max_sum:
              self.current_max_sum = res 
          return max(node.val, node.val + maxPathSumLeft, node.val + maxPathSumRight) 
```
