## Problem 1: House Robber
URL: https://leetcode.com/problems/house-robber/description/


Status:
```
  ✔ Accepted
```

```ruby
def rob(houses)
  houses_count = houses.size
  return 0 if houses_count.zero?
  if houses_count < 3
    houses.max
  elsif houses_count < 4
    [houses[1], houses[0] + houses[2]].max
  else
    houses[2] += houses[0]
    max = houses[2]
    for i in (3..houses_count - 1)
      houses[i] += [houses[i - 2], houses[i - 3]].max
      max = houses[i] if houses[i] > max
    end
    max
  end
end
```
