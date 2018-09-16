## Problem 1

https://leetcode.com/problems/path-sum-iii/description/

Hold an array of sums from previous parents. At each step, add current node value to each member in the array; and append current node value to the array. Count upon that array

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
    run(root, [], sum)
end

def run(node, previous_sums, sum)
    current_sums = previous_sums.map { |s| s + node.val } + [node.val]
    count_left = node.left.nil? ? 0 : run(node.left, current_sums, sum)
    count_right = node.right.nil? ? 0 : run(node.right, current_sums, sum)
    count_current = current_sums.count(sum)
    count_left + count_right + count_current
end
```
