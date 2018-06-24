## Problem 1
Link: https://leetcode.com/problems/find-the-difference

 * 54 / 54 test cases passed.
 * Status: Accepted
 * Runtime: 64 ms
 
```ruby
# @param {String} s
# @param {String} t
# @return {Character}
def find_the_difference(s, t)
  hash = {}
  for i in 0..s.length-1 do
    hash[s[i]] = hash[s[i]].nil? ? 1 : hash[s[i]] + 1
  end
  for i in 0..t.length-1 do
    return t[i] if hash[t[i]].nil? || hash[t[i]] == 0
    hash[t[i]] = hash[t[i]] - 1
  end
end
```

## Problem 2
Link: https://leetcode.com/problems/binary-tree-level-order-traversal

 * 34 / 34 test cases passed.
 * Status: Accepted
 * Runtime: 40 ms
 
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
# @return {Integer[][]}
def level_order(root)
  stack = []
  result = []
  stack << {node: root, level: 0}
  while !stack.empty?
    node_with_level = stack.pop
    next if node_with_level[:node].nil?
    if result[node_with_level[:level]].nil?
      result << [node_with_level[:node].val]
    else
      result[node_with_level[:level]] << node_with_level[:node].val
    end
    
    stack << {node: node_with_level[:node].right, level: node_with_level[:level] + 1}
    stack << {node: node_with_level[:node].left, level: node_with_level[:level] + 1}
  end
  result
end
```