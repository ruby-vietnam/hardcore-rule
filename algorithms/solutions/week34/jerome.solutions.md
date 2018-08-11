## Problem 1 (https://leetcode.com/problems/house-robber/description/)
```ruby

def rob(nums)
  house_length = nums.length
  return 0 if house_length == 0
  return nums[0] if house_length == 1

  temp = Array.new(house_length) { 0 }
  temp[0] = nums[0]
  temp[1] = [nums[0], nums[1]].max

  for i in 2..(house_length - 1)
    temp[i] = [temp[i - 2] + nums[i], temp[i - 1]].max
  end

  temp[-1]
end

```
