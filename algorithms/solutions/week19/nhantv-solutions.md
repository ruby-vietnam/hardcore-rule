# Problem 1: Hamming Distance

https://leetcode.com/problems/hamming-distance/description/

```
Runtime: 32 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {Integer} x
# @param {Integer} y
# @return {Integer}
def hamming_distance(x, y)
  count = 0
  until x == 0 && y == 0
    count += 1 if x % 2 != y % 2
    x >>= 1
    y >>= 1
  end
  count
end
==============================
def hamming_distance(x, y)
  count = 0
  diff = x ^ y
  while diff > 0
    count += 1
    diff &= (diff - 1)
  end
  count
end
```
