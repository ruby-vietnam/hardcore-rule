# Problem 1

```ruby
def is_anagram(s, t)
  return false if s.length != t.length
  h = {}
  i = 0
  while i < s.length
    s_i = s[i].ord
    t_i = t[i].ord

    h[s_i] ||= 0
    h[t_i] ||= 0

    h[s_i] += 1
    h[t_i] -= 1

    i += 1
  end
  h.values.reject(&:zero?).none?
end
```
