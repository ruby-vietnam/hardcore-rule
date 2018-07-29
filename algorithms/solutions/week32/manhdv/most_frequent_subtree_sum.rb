# https://leetcode.com/problems/most-frequent-subtree-sum/description/

# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

def fetch_sum(node, sum, sum_frequent)
  return if node.nil?
  sum += node.val
  sum += fetch_sum(node.left, 0, sum_frequent) unless node.left.nil?
  sum += fetch_sum(node.right, 0, sum_frequent) unless node.right.nil?
  sum_frequent[sum] ||= 0
  sum_frequent[sum] += 1
  sum
end

# @param {TreeNode} root
# @return {Integer[]}
def find_frequent_tree_sum(root)
  sum_frequent = {}
  fetch_sum(root, 0, sum_frequent)
  max_frequent = sum_frequent.values.sort.max
  sum_frequent.select { |_, v| v == max_frequent }.keys
end
