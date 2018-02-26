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
