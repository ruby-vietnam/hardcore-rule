## Problem 1

```ruby
def valid_palindrome(s)
  palindrome?(s) || can_become_palindrome?(s)
end

def palindrome?(s)
  s == s.reverse
end

def can_become_palindrome?(s)
  start = 0
  finish = s.length - 1
  count = 1

  while start < finish
    if s[start] != s[finish]
      new_s_1 = s.dup
      new_s_1.slice!(start)
      new_s_2 = s.dup
      new_s_2.slice!(finish)
      return palindrome?(new_s_1) || palindrome?(new_s_2)
    else
      start += 1
      finish -= 1
    end
  end

  true
end
```

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
