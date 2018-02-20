## Problem 1

```ruby
def find_lhs(nums)
  hash = Hash.new(0)

  nums.each do |n|
    hash[n] += 1
  end

  max = 0
  list = hash.keys.sort

  (list.length - 1).times do |i|
    n1 = list[i]
    n2 = list[i + 1]
    if n2 - n1 == 1 && hash[n2] + hash[n1] > max
      max = hash[n2] + hash[n1]
    end
  end

  max
end
```

## Problem 2

```ruby
def merge_trees(t1, t2)
  return nil if t1.nil? && t2.nil?

  new_tree = TreeNode.new(0)
  stack = [[t1, t2, new_tree]]

  while !stack.empty? do
    t1, t2, new_t = stack.pop
    t1 ||= TreeNode.new(0)
    t2 ||= TreeNode.new(0)

    new_t.val = t1.val + t2.val

    if !(t1.left.nil? && t2.left.nil?)
      new_t.left = TreeNode.new(0)
      stack.push([t1.left, t2.left, new_t.left])
    end

    if !(t1.right.nil? && t2.right.nil?)
      new_t.right = TreeNode.new(0)
      stack.push([t1.right, t2.right, new_t.right])
    end
  end

  new_tree
end
```
