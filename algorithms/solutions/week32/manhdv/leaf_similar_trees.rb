# https://leetcode.com/problems/leaf-similar-trees/description/

# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

def fetch_leaves(node, leaves)
  node.left.nil? && node.right.nil? && leaves << node.val

  fetch_leaves(node.left, leaves) unless node.left.nil?
  fetch_leaves(node.right, leaves) unless node.right.nil?

  leaves
end

# @param {TreeNode} root1
# @param {TreeNode} root2
# @return {Boolean}
def leaf_similar(root1, root2)
  fetch_leaves(root1, []) == fetch_leaves(root2, [])
end
