## Problem 1

Hamming distance
https://leetcode.com/problems/hamming-distance/description/

```ruby
MASK = 0x00000001
def hamming_distance(x, y)
    d = 0
    loop do
        break if x == 0 && y == 0
        d += 1 if x & MASK != y & MASK 
        x = x >> 1
        y = y >> 1
    end
    d
end
```
