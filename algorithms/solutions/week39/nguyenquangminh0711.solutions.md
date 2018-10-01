## Problem 1

https://leetcode.com/problems/reverse-integer/description/

```ruby
# @param {Integer} x
# @return {Integer}
def reverse(x)
    x = x.to_s.reverse.to_i * (x < 0 ? -1 : 1)
    (x > 2**31 - 1 || x < -2**31) ? 0 : x
end
```
