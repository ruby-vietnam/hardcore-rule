# 205

```ruby
def is_isomorphic(s, t)
  mappings = {}
  flags = {}
  s.length.times do |i|
    if mappings[s[i]]
      if mappings[s[i]] != t[i]
        return false
      end
    else
      unless flags[t[i]]
        mappings[s[i]] = t[i]
        flags[t[i]] = true
      else
        return false
      end
    end
  end
  return true
end
```
