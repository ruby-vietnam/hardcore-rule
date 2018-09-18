## Problem 1 (https://leetcode.com/problems/reverse-integer/description/)

```ruby
# @param {Integer} x
# @return {Integer}
def reverse(x)
  result = 0
  temp = x
  x *= -1 if x < 0

  while x != 0
    rem = x % 10
    result = result * 10 + rem
    x = x / 10
  end

  temp < 0 ? result *= -1 : result
  result < -2 ** 31 || result > 2 ** 31 - 1 ? 0 : result
end
```
