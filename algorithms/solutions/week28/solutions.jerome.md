## Problem 1

```ruby

def check_possibility(nums)
  count = 0
  length = nums.length
  for i in 0...(length - 1)
    if nums[i] > nums[i + 1]
      count += 1

      if i > 0
        nums[i - 1] <= nums[i + 1] ? nums[i] = nums[i - 1] : nums[i + 1] = nums[i]
      else
        nums[i] = nums[i + 1]
      end
    end

    return false if count >= 2
  end

  true
end

```

## Problem 2

```ruby

def permute(list)
  return [list] if list.length == 1

  result = []

  for i in 0..(list.length - 1)
    num = list[i]
    sublist = list - [num]
    perms = permute(sublist)

    perms.each do |perm|
      result << [num] + perm
    end
  end

  result
end

```

## Problem 3

```ruby

# Definition for a binary tree node.
# class TreeNode
#   attr_accessor :val, :left, :right
#   def initialize(val)
#     @val = val
#     @left, @right = nil, nil
#   end
# end

# Encodes a tree to a single string.
#
# @param {TreeNode} root
# @return {string}

def serialize(root)
  result = []
  q = [root]

  while !q.empty? && !q.compact.empty?
    node = q.shift

    if node
      result.push(node.val)
      q.push(node.left)
      q.push(node.right)
    else
      result.push("null")
    end
  end

  "[#{result.join(",")}]"
end

# # Decodes your encoded data to tree.
# #
# # @param {string} data
# # @return {TreeNode}

def deserialize(data)
  map = data[1..-2].split(",").map do |element|
    if element != "null"
      element.to_i
    else
      nil
    end
  end

  root = TreeNode.new(map.shift)
  q = [root]

  while !map.empty?
    node = q.shift

    left = map.shift
    right = map.shift

    if left
      left_node = TreeNode.new(left)
      q.push(left_node)
      node.left = left_node
    end

    if right
      right_node = TreeNode.new(right)
      q.push(right_node)
      node.right = right_node
    end
  end

  root
end

# # Your functions will be called as such:
# # deserialize(serialize(data))

```
