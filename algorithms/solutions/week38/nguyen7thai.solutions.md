## Problem 1
https://leetcode.com/problems/path-sum-iii/description/

```
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
def path_recur(root, result, sum)
    result[:count] += 1 if root.val == sum
    return [root.val] if !root.left && !root.right
    paths = [root.val]
    if root.left
        left = path_recur(root.left, result, sum)
        left.each do |l|
            yo = root.val + l
            result[:count] += 1 if yo == sum
            paths.push(yo)
        end
    end
    if root.right
        right = path_recur(root.right, result, sum)
        right.each do |l|
            yo = root.val + l
            result[:count] += 1 if yo == sum
            paths.push(yo)
        end
    end
    paths
end

def path_sum(root, sum)
    result = { count: 0 }
    return 0 if !root
    path_recur(root, result, sum)
    result[:count]
end
```
