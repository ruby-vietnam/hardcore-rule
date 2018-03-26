## Problem 1

https://leetcode.com/problems/power-of-four/description/

Recursive until we could not divide by 4 again. 

```ruby
# @param {Integer} num
# @return {Boolean}
def is_power_of_four(num)
    if num == 1
        return true
    elsif num < 4
        return false
    else
        num % 4 == 0 && is_power_of_four(num / 4)
    end 
end
```
