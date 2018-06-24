# Problem 1

```ruby
def find_the_difference(s, t)
  map = {}
  s.each_char do |c|
    map[c] ||= 0
    map[c] += 1
  end

  t.each_char do |c|
    return c if map[c].to_i.zero?
    map[c] -= 1
  end
end
```
