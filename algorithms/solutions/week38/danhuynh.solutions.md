# Problem 1
```ruby
# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

def path_sum_helper(root, sum)
  return 0 unless root

  count = root.val == sum ? 1 : 0

  count += path_sum_helper(root.left, sum - root.val)
  count += path_sum_helper(root.right, sum - root.val)

  return count
end

# @param {TreeNode} root
# @param {Integer} sum
# @return {Integer}
def path_sum(root, sum)
  return 0 unless root
  path_sum_helper(root, sum) + path_sum(root.left, sum) + path_sum(root.right, sum)
end
```
