## Problem 1
Link: https://leetcode.com/problems/power-of-three
 * 21038 / 21038 test cases passed.
 * Status: Accepted

```ruby
# @param {Integer} n
# @return {Boolean}
def is_power_of_three(n)
    return n > 0 && (3**19%n).zero?
end
```
