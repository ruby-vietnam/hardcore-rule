# Problem 2

https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

Solutions:
- First, we calculate the max maximum path, starts at the each node. This sum will be the max of
  + Current node value + the maximum path starting at left children
  + Current node value + the maximum path starting at right children
  + Current node value (the path length is 1)
- After that, we find node with highest sum in all node. However, there is a case that the maximum path would go up and down again. In that case, we just need to compare one more case: (node left sum + node right sum + current node value).

- Complexity: O(2*n) => O(n); n is the number of nodes

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
# @return {Integer}
def max_path_sum(root)
    TreeNode.send(:attr_accessor, :sum)
    
    calculate_sums(root)
    find_max_sum(root)
end

def calculate_sums(node)
    return 0 if node.nil?
    node.sum = [
        calculate_sums(node.left) + node.val,
        calculate_sums(node.right) + node.val,
        node.val
    ].max
    node.sum
end

def find_max_sum(node)
    if node.left.nil? && node.right.nil?
        node.sum
    elsif node.left.nil?
        [node.sum, find_max_sum(node.right)].max
    elsif node.right.nil?
        [node.sum, find_max_sum(node.left)].max
    else
        [
          node.sum,
          find_max_sum(node.right),
          find_max_sum(node.left),
          (node.left.sum + node.right.sum + node.val)
        ].max
    end
end
```
