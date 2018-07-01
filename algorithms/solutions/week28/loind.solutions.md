# Problem 1

```ruby
def check_possibility(nums)
  count = 0
  n = nums.size - 1

  n.times do |i|
    if nums[i] > nums[i+1]
      count += 1
      if i > 0 && nums[i + 1] < nums[i - 1]
        nums[i + 1] = nums[i]
      else
        nums[i] = nums[i + 1]
      end
    end
  end
  count <= 1
end
```
