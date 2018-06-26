## Problem 1

```ruby
# @param {Integer[]} nums
# @return {Boolean}
def check_possibility(nums)
  error_count = 0

  0.upto(nums.size-2).each do |i|
    next if nums[i] <= nums[i+1]
    error_count += 1
    nums[i+1] = nums[i] if i != 0 && nums[i-1] > nums[i+1]

    return false if error_count > 1
  end

  true
end
```

## Problem 2

```ruby
# @param {Integer[]} nums
# @return {Integer[][]}
def permute(nums)
  return [nums] if nums.size == 1
  nums.map do |num|
    permute(nums - [num]).map{|per| [num] + per}
  end.flatten(1)
end
```
