# Problem 1 

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
    sequence1 = get_leaf_sequence(root1)
    sequence2 = get_leaf_sequence(root2)
    sequence1 == sequence2
end

def get_leaf_sequence(root, result = [])
    return result if root.nil?
    result << root.val if root.left.nil? && root.right.nil?
    get_leaf_sequence(root.left, result)
    get_leaf_sequence(root.right, result)
end
```