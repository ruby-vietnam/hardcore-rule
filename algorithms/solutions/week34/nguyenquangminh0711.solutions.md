## Problem 1

https://leetcode.com/problems/house-robber/description/

Simple dynamic programming problem. The fomula: T[i] = [T[i-1], T[i-2] + A[i]].max

```ruby
# @param {Integer[]} nums
# @return {Integer}
def rob(houses)
    return 0 if houses.length == 0
    return houses[0] if houses.length == 1
    
    money = [houses[0]]
    money[1] = [houses[0], houses[1]].max
    i = 2
    while i < houses.length
        money[i] = [money[i - 1], money[i - 2] + houses[i]].max
        puts money.inspect
        i += 1
    end
    
    money[houses.length - 1]
end
```
