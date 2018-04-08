## Problem 1

https://leetcode.com/problems/move-zeroes/description/

Loop from left to right, if nums[i] is zero, exchange with the next non-zero number. Since the positions are cached, the complexity is O(n)

```ruby
# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def move_zeroes(nums)
    i = 0
    j = 0
    loop do
        break if i >= nums.length || j >= nums.length
        if nums[i] == 0
            j += 1
            if j < nums.length && nums[j] != 0
                nums[i] = nums[j]
                nums[j] = 0
            end
        else
            i += 1
            j = i if j < i
        end
    end
end
```
