# Problem 1: Find the Difference

https://leetcode.com/problems/find-the-difference/description/

```
Runtime: 52 ms
Your runtime beats 76.00 % of ruby submissions.
```

```ruby
# @param {String} s
# @param {String} t
# @return {Character}
def find_the_difference(s, t)
  h = Hash.new(0)
  s.each_char do |c|
    h[c] += 1
  end
  t.each_char do |c|
    h[c] -= 1
    return c if h[c] < 0
  end
end
```

# Problem 2: Binary Tree Level Order Traversal

https://leetcode.com/problems/binary-tree-level-order-traversal/description/

```
Runtime: 40 ms
Your runtime beats 94.92 % of ruby submissions.
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
# @return {Integer[][]}
def level_order(root)
  return [] unless root
  bfs([[root]], [], 0)
end

def bfs(nodes, values, level)
  return values unless nodes[level]
  values[level] ||= []   # initialize array
  values[level].push(nodes[level][0].val)
  if nodes[level][0].left
    nodes[level + 1] ||= []  # initialize array
    nodes[level + 1].push(nodes[level][0].left)
  end
  if nodes[level][0].right
    nodes[level + 1] ||= []  # initialize array
    nodes[level + 1].push(nodes[level][0].right)
  end
  nodes[level].shift
  level += 1 if nodes[level].length == 0
  bfs(nodes, values, level)
end
```
