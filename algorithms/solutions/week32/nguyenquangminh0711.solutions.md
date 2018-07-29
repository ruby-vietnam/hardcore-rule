## Problem 1

https://leetcode.com/problems/leaf-similar-trees/description/

Nothing to say, just travese the tree to the end to get the leaf nodes.

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
    left_values_1 = find_leaf_values(root1)
    left_values_2 = find_leaf_values(root2)
    left_values_1 == left_values_2
end

def find_leaf_values(node)
    if node.nil?
        return []
    elsif node.left.nil? && node.right.nil?
        return [node.val]
    else
        return find_leaf_values(node.left) + find_leaf_values(node.right)
    end
end
```

## Problem 2

https://leetcode.com/problems/most-frequent-subtree-sum/description/

Create a hash to store the count of sums. Traverse the tree. At each node, calculate the left sum, the right sum, update the hash count and go up.

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
# @return {Integer[]}
def find_frequent_tree_sum(root)
    return [] if root.nil?
    
    sums = {}
    traverse(root, sums)
    
    max = [sums.keys.first]
    sums.keys[1..-1].each do |sum|
        if sums[sum] > sums[max.first]
            max = [sum]
        elsif sums[sum] == sums[max.first]
            max << sum
        end
    end
    
    max
end

def traverse(node, sums)
    return 0 if node.nil?
    sum = node.val + traverse(node.left, sums) + traverse(node.right, sums)
    sums[sum] ||= 0
    sums[sum] += 1
    sum
end
```
