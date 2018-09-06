## Problem 1

```ruby
# @param {Integer} n
# @return {Boolean}
def is_power_of_three(n)
    return false if n <= 0 
    3 ** 19 % n == 0
end
```
