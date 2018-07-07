# serde_bintree

```ruby
# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# Encodes a tree to a single string.
#
# @param {TreeNode} root
# @return {string}
def serialize(root)
  return "null" if root.nil?
  s = root.val.to_s + "," + serialize(root.left) + "," + serialize(root.right)
end

# Decodes your encoded data to tree.
#
# @param {string} data
# @return {TreeNode}
def d(data)
  return [nil, nil] if data.nil?
  value, rest = data.split(",",2)
  return [nil, rest] if value == "null"
  node = TreeNode.new(value.to_i)
  node.left, rest = d(rest)
  node.right, rest = d(rest)

  [node, rest]
end

def deserialize(data)
  node, t = d(data)
  node
end


# Your functions will be called as such:
# deserialize(serialize(data))
```