## Problem 1

```ruby
# @param {String} s
# @param {String} t
# @return {Character}

def find_the_difference(s, t)
  hash = Hash.new { |hash, key| hash[key] = 0 }

  for i in 0..(t.length - 1)
    hash[s[i]] += 1
    hash[t[i]] -= 1
  end

  for k in hash.keys
    return k if hash[k] == -1
  end
end
```

## Problem 2

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
  return [] if !root

  current_lv = 0
  q = [[root, current_lv]]
  result = []

  while !q.empty?
      node, current_lv = q.shift
      result[current_lv] ||= []
      result[current_lv] << node.val
      q.push([node.left, current_lv + 1]) if node.left
      q.push([node.right, current_lv + 1]) if node.right
  end

  result
end
```
