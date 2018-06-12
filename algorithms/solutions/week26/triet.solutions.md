## Problem 1

```ruby
# @param {String} s
# @param {String} t
# @return {Character}
def find_the_difference(s, t)
  h = Hash.new(0)
  s.each_char { |c| h[c] += 1}
  t.each_char { |c| h[c] -= 1}
  h.each { |key, value| return key if value != 0}
end
```
