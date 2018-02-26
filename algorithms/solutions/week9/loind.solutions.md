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
