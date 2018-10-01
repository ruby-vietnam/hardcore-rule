## Problem 1
Link: https://leetcode.com/problems/power-of-three
 * 126 / 126 test cases passed.
 * Status: Accepted

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
# @param {Integer} sum
# @return {Integer}
def path_sum(root, sum)
    return 0 if root.nil?
    sum_from(root, sum) + path_sum(root.left, sum) + path_sum(root.right, sum)
end

def sum_from(node, sum)
    return 0 if node.nil?
    (node.val == sum ? 1 : 0) + sum_from(node.left, sum - node.val) + sum_from(node.right, sum - node.val)
end


```
