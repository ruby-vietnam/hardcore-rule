# https://leetcode.com/problems/binary-tree-level-order-traversal/description/

def trace_node(node, level, result)
  return if node.nil?

  result[level] ||= []
  result[level] << node.val unless node.val.nil?

  trace_node(node.left, level + 1, result) unless node.left.nil?
  trace_node(node.right, level + 1, result) unless node.right.nil?
end

# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer[][]}
def level_order(root)
  result = {}

  trace_node(root, 0, result)

  result.values
end
