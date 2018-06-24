## Problem 1

```
def find_the_difference(s, t)
  base = 'a'.ord
  check = Array.new(26) { 0 }

  s.each_char do |c|
    check[c.ord - base] += 1
  end

  t.each_char do |c|
    check[c.ord - base] -= 1
  end

  check.each_with_index do |value, index|
    if value < 0
      return (base + index).chr
    end
  end
end
```
