# Problem 2: Binary Tree Maximum Path Sum

https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

```
Runtime: 76 ms
Your runtime beats 88.24 % of ruby submissions.
```

```ruby
# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer}
def max_path_sum(root)
  find_max_path_sum(root)[0]
end

def find_max_path_sum(root)
  return [nil, 0] if root.nil?
  return [root.val, root.val] if root.left.nil? && root.right.nil?
  left = find_max_path_sum(root.left)
  right = find_max_path_sum(root.right)
  root_left = root.val + left[1]
  root_right = root.val + right[1]
  root_left_right = root.val + left[1] + right[1]
  current = [root.val, root_left, root_right].max
  max = [left[0], right[0], root_left_right].compact.max
  max = current if current > max
  return [max, current]
end
```
