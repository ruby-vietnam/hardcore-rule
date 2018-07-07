# https://leetcode.com/problems/non-decreasing-array/description/

```ruby
def non_decreasing_array?(nums)
  0.upto(nums.size - 2) do |idx|
    return false if nums[idx] > nums[idx + 1]
  end

  true
end

def replace_value(array, idx, new_value)
  array.dup.tap { |arr| arr[idx] = new_value }
end

# @param {Integer[]} nums
# @return {Boolean}
def check_possibility(nums)
  0.upto(nums.size - 2) do |idx|
    num = nums[idx]
    num_right = nums[idx + 1]

    if num > num_right
      return non_decreasing_array?(replace_value(nums, idx, num_right)) ||
      non_decreasing_array?(replace_value(nums, idx + 1, num))
    end
  end

  true
end
```