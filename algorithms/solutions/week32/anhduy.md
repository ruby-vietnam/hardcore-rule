# 862

```ruby
def leaf_similar(root1, root2)
  leaf1 = find_leafs(root1)
  leaf2 = find_leafs(root2)
  leaf1 == leaf2
end

def find_leafs(root, result = [])
  return result unless root

  if (root.left == nil && root.right == nil)
    result.push(root.val)
  else
    result = find_leafs(root.left, result)
    result = find_leafs(root.right, result)
  end

  return result
end
```
