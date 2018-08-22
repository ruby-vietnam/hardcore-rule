## Problem 1
Link: https://leetcode.com/problems/house-robber

 * 69 / 69 test cases passed.
 * Status: Accepted

```ruby
# @param {Integer[]} nums
# @return {Integer}
# A(n) = MAX(n + A(i-2), A(i-1))
def rob(nums)
    res = []
    res << 0
    res << nums[0]
    (1 .. nums.length - 1).each do |i|
        res << [res[i], res[i-1] + nums[i]].max
    end
    p res
    res[nums.length]
end
```
