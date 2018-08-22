## Problem 1
https://leetcode.com/problems/house-robber/description/

```
# @param {Integer[]} nums
# @return {Integer}
def rob(nums)
    save = []
    return 0 if nums.count == 0
    return nums.max if nums.count <= 2
    a1 = nums[0]
    a2 = [nums[0], nums[1]].max
    a3 = 0
    (2..(nums.count-1)).each do |i|
        a3 = [a2, a1 + nums[i]].max
        a1 = a2
        a2 = a3
    end
    a3
end
```
