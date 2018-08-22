## Problem 1

```ruby
def leaf_similar(root_1, root_2)
  array_1 = leaves(root_1)
  array_2 = leaves(root_2)

  array_1 == array_2
end

def leaves(root)
  if root.left.nil? && root.right.nil?
    [root.val]
  elsif root.left.nil?
    leaves(root.right)
  elsif root.right.nil?
    leaves(root.left)
  else
    leaves(root.left) + leaves(root.right)
  end
end
```

## Problem 2

```ruby
def find_frequent_tree_sum(root)
  return [] if root.nil?

  hash = Hash.new { 0 }
  calculate_sum(root, hash)

  max = hash.values.max

  hash.inject([]) do |result, (key, value)|
    if value == max
      result << key
    end

    result
  end
end

def calculate_sum(root, hash)
  if root.left.nil? && root.right.nil?
    root.val
  elsif root.left.nil?
    root.val + calculate_sum(root.right, hash)
  elsif root.right.nil?
    root.val + calculate_sum(root.left, hash)
  else
    root.val + calculate_sum(root.left, hash) + calculate_sum(root.right, hash)
  end.tap do |sum|
    hash[sum] += 1
  end
end
```
