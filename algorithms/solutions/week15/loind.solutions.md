# Problem 1

```ruby
def find_next_non_zero_number_index(nums, start)
  n = nums.size
  i = start
  while i < n
    return i unless nums[i].zero?
    i += 1
  end
  nil
end

def move_zeroes(nums)
  i = 0
  n = nums.size - 1
  while i < n
    if nums[i].zero?
      index = find_next_non_zero_number_index(nums, i + 1)
      return nums if index.nil?
      nums[i], nums[index] = nums[index], nums[i]
    end
    i += 1
  end
  nums
end
```
