## Problem 3 (https://leetcode.com/problems/power-of-three/description/)

```ruby
def is_power_of_three(n)
  return false if n <= 0

  while n % 9 == 0
    n = n / 9
  end

  n == 1 || n == 3
end

```
