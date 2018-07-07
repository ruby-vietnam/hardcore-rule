# non_decreasing_array

```ruby
def check_possibility(nums)
  count = 0

  nums.each_with_index do |num, index|
    next if index == 0

    if nums[index - 1] > num
      return false if count > 0
      count += 1

      if (index == 1) || (nums[index - 2] <= num)
        nums[index - 1] = num
      else
        nums[index] = nums[index - 1]
      end
    end
  end

  true
end
```