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

## Problem 3

```ruby
def is_subsequence(s, t)
  i = 0
  j = 0

  while i < s.size && j < t.size
    if s[i] == t[j]
      i += 1
      j += 1
    else
      j += 1
    end
  end

  i == s.size
end
```
