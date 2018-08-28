## Problem 1 (https://leetcode.com/problems/climbing-stairs/description/)
```ruby

# @param {Integer} n
# @return {Integer}
def climb_stairs(n)
  return n if n <= 2

  a, b = 1, 2

  for i in 3..n
    current = a + b
    a = b
    b = current
  end

  b
end

```
