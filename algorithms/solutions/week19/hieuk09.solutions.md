## Problem 1

```ruby
def hamming_distance(x, y)
  count = 0

  32.times.each do |n|
    if x > 0 || y > 0
      if x % 2 != y % 2
        count += 1
      end

      x /= 2
      y /= 2
    else
      break
    end
  end

  count
end
```
