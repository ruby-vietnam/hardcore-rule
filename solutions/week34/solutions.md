## Problem 1
Link: https://leetcode.com/problems/house-robber

69 / 69 test cases passed.
Status: Accepted
Runtime: 88 ms

```ruby
# @param {Integer[]} nums
# @return {Integer}
# This solution has O(n-1) time complexity and uses O(1) space
def rob(nums)
    return 0 if nums.length == 0
    robbed = nums[0]
    not_robbed = 0
    for index in 1..(nums.length - 1) do
        current = nums[index]
        prev_not_robbed = not_robbed
        prev_robbed = robbed
        robbed = current + prev_not_robbed
        not_robbed = [prev_not_robbed, prev_robbed].max
    end
    
    return [not_robbed, robbed].max
end
```