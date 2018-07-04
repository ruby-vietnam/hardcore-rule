## Problem 1
Link: https://leetcode.com/problems/non-decreasing-array

 * 325 / 325 test cases passed.
 * Status: Accepted
 * Runtime: 56 ms
 
```ruby
# @param {Integer[]} nums
# @return {Boolean}
def check_possibility(nums)
  prev = nums[0]
  count = 0
  nums.each_with_index do |n, i|
    if n < prev
      count += 1
      if count == 2
        return false
      end
      if i > 1 && i < nums.length - 1 && nums[i] <= nums[i-2] && nums[i+1] < nums[i-1]
        return false
      end
    end
    prev = n
  end

  return true
end
```
