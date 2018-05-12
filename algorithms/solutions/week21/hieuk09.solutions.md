## Problem 1

```ruby
A_ORD = 'a'.ord

def is_anagram(s, t)
  check_s = traverse(s)
  check_t = traverse(t)

  check_s == check_t
end

def traverse(s)
  s.each_byte.inject(Array.new(26) { 0 }) do |result, c|
    result[c.ord - A_ORD] += 1
    result
  end
end
```
