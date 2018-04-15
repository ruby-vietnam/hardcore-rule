# Problem 1

```ruby
def is_isomorphic(s, t)
  mc = {}
  mt = {}
  s.each_char.with_index do |sc, i|
    tc = t[i]
    return false if mc[sc] != mt[tc]
    mc[sc] = mt[tc] = i
  end
  true
end
```
