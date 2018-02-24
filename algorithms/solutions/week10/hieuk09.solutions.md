## Problem 2

```ruby
def flatten(root)
  return unless root

  left = root.left
  right = root.right

  if left
    root.right = left
    root.left = nil
    last = flatten(left)
    last.right = right
    if right
      flatten(right)
    else
      last
    end
  elsif right
    flatten(right)
  else
    root
  end
end
```
