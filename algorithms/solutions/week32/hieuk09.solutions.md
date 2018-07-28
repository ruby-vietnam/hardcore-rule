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
