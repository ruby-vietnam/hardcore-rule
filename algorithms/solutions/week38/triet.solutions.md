## Problem 1

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
  travel(root, [], sum)  
end

def travel(node, arr_sum, sum)
  return 0 if node.nil?
  total = 0
  na = arr_sum.map{|s| s + node.val} << node.val
  # Check if any is sum
  total = na.count{|s| s == sum}
  
  total += travel(node.left, na, sum)
  total += travel(node.right, na, sum)
  total
end
```
