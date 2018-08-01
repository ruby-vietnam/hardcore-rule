## Problem 1 (https://leetcode.com/problems/leaf-similar-trees/description/)
```ruby

# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root1
# @param {TreeNode} root2
# @return {Boolean}

def dfs(root)
  q = [root]
  result = []
  while !q.empty?
    node = q.pop

    if node
      if node.right.nil? && node.left.nil?
        result << node.val
      else
        q << node.left
        q << node.right
      end
    end
  end

  result
end

def leaf_similar(root1, root2)
  dfs(root1) == dfs(root2)
end

```
