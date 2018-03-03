# Problem 1

```ruby
def palindrome?(s, low, high)
  while low < high
    return false if s[low] != s[high]
    low += 1
    high -= 1
  end
  true
end

def valid_palindrome(s)
  low = 0
  high = s.length - 1
  while low < high
    if s[low] == s[high]
      low += 1
      high -= 1
    else
      return palindrome?(s, low + 1, high) || palindrome?(s, low, high - 1)
    end
  end
  true
end
```

# Problem 2

```ruby
def traversal(node, arr)
  return if node.nil?
  arr.push node.val
  traversal(node.left, arr)
  traversal(node.right, arr)
  arr
end

def flatten(root)
  arr = traversal(root, [])
  return if arr.nil?
  arr.drop(1).each do |e|
    root.left = nil
    root.right = TreeNode.new(e)
    root = root.right
  end
end
```

# Problem 3

```ruby
def is_subsequence(s, t)
  s_index = 0
  t_index = 0
  while s_index < s.length
    while t_index < t.length
      if t[t_index] == s[s_index]
        s_index += 1
        t_index += 1
      else
        t_index += 1
      end
    end
    return false if t_index == t.length && s_index < s.length
  end
  s_index == s.length ? true : false
end
```
