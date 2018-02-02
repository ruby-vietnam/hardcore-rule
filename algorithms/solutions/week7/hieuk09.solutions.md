## Problem 1

```ruby
def first_uniq_char(s)
  counts = Array.new(26, 0)
  indices = Array.new(26, nil)
  start = 'a'.ord

  s.each_char.each_with_index do |c, index|
    position = c.ord - start
    indices[position] ||= index
    counts[position] += 1
  end

  min = nil

  26.times do |index|
    if counts[index] == 1 && (min.nil? || min > indices[index])
      min = indices[index]
    end
  end

  min || -1
end
```
