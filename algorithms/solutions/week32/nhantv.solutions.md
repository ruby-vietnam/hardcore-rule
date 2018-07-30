# Problem 1: Leaf-Similar Trees

https://leetcode.com/problems/leaf-similar-trees/description/

```
Runtime: 52 ms
Your runtime beats 27.78 % of ruby submissions.
```

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
  leaves(root1) == leaves(root2) 
end

def leaves(root)
  return [] unless root
  return [root.val] unless root.left || root.right
  leaves(root.left) + leaves(root.right)
end
```

# Problem 2: Most Frequent Subtree Sum

https://leetcode.com/problems/most-frequent-subtree-sum/description/

```
Runtime: 60 ms
Your runtime beats 71.43 % of ruby submissions.
```

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
  return [] unless root
  @hash = Hash.new(0)
  find_frequent_subtree_sum(root)
  max = 0
  @hash.each { |_,v| max = v if max < v }
  result = []
  @hash.each { |k, v| result << k if v == max }
  result
end

def find_frequent_subtree_sum(root)
  left = root.left ? find_frequent_subtree_sum(root.left) : 0
  right = root.right ? find_frequent_subtree_sum(root.right) : 0
  sum = root.val + left + right
  @hash[sum] += 1
  sum
end
```
