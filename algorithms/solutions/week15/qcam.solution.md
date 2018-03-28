# P1

```rb
def move_zeroes(nums)
  return if nums.size == 1

  current_zero_index = 0
  nums.each_with_index do |num, index|
    if num != 0
      nums[index] = 0
      nums[current_zero_index] = num
      current_zero_index += 1
    end
  end
end
```
