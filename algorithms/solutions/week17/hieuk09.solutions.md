## Problem 1

```ruby
def is_isomorphic(s, t)
  size = s.length
  check_s = []
  check_t = []

  size.times do |index|
    s_char = s[index].ord
    t_char = t[index].ord
    if check_s[s_char] != check_t[t_char]
      return false
    else
      check_s[s_char] = check_t[t_char] = index
    end
  end

  true
end
```
