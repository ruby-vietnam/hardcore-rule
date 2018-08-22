## Problem 1

https://leetcode.com/problems/leaf-similar-trees/description/

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
def leaf_similar(root1, root2)
  leaf1 = get_leaf(root1)
  leaf2 = get_leaf(root2)
  return false if leaf1.length != leaf2.length
  
  leaf1.each.with_index { |leaf, index|
    return false if leaf != leaf2[index]
  }

  return true
end

def get_leaf(root)
  leaf_values = []
  stack = [root]
  
  while stack.length > 0 
    node = stack.pop
    stack.push(node.right) unless node.right.nil?
    stack.push(node.left) unless node.left.nil?
    
    if node.left.nil? && node.right.nil? 
      leaf_values << node.val
    end
  end
  
  leaf_values
end
```
