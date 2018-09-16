# Problem 1

```ruby
def reverse(x)
  s = x.to_s.tr('-', '')
  n = s.length
  i = n - 1
  sr = x > 0 ? '' : '-'

  while i >= 0
    if sr.empty?
      sr += s[i] if s[i] > '0'
    else
      sr += s[i]
    end
    i -= 1
  end
  min = -2**31
  max = (2**31) - 1
  result = sr.to_i
  (min..max).cover?(result) ? result : 0
end
```
