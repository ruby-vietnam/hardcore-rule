# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

CACHE = {}
# @param {TreeNode} root
# @return {Integer}

def h(root)
    return nil if root.nil?
    [root.val, max_path_sum_at(root), h(root.left), h(root.right)].compact.max
end

def max_path_sum(root)
    CACHE.clear
    h(root)
end

# Path sum INCLUDING root
def max_path_sum_at(root)
    return nil if root.nil?
    left_sum = max_single_path_sum(root.left)
    right_sum = max_single_path_sum(root.right)
    [left_sum, right_sum, left_sum + right_sum].compact.max + root.val
end

def max_single_path_sum(root)
    CACHE[root] ||= t(root)
end

def t(root)
    return 0 if root.nil?
    return root.val if root.left.nil? && root.right.nil?
    if root.left.nil?
        return [max_single_path_sum(root.right) + root.val, root.val].max
    end
    if root.right.nil?
        return [max_single_path_sum(root.left) + root.val, root.val].max
    end
    return [[max_single_path_sum(root.left), max_single_path_sum(root.right)].max + root.val, root.val].max
end

