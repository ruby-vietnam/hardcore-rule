## Problem 2

https://leetcode.com/problems/permutations/description/

Start from the end, find the first element i that is smaller than its next element. Then, find the smallest element that smaller than i, swap those two number. Then, rotate from i + 1 to the end, we'll have a ner permuatation

```ruby
# @param {Integer[]} nums
# @return {Integer[][]}
def permute(nums)
    nums.sort!
    permuations = [nums.dup]
    
    loop do
        i = nums.length - 1
        while i > 0 && nums[i] < nums[i - 1]
            i -= 1
        end
        break if i == 0
        
        k = i
        (i..nums.length - 1).each do |j|
            if nums[j] > nums[i - 1] && nums[k] > nums[j]
                k = j
            end
        end
        nums[i - 1], nums[k] = nums[k], nums[i - 1]
        
        mid = (i + nums.length - 1) / 2
        (i..mid).each do |j|
            nums[j], nums[i + nums.length - 1 -j] = nums[i + nums.length - 1 -j], nums[j]
        end
        permuations << nums.dup
    end
    permuations
end
```
