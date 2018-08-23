# Problem 1
```ruby
def rob(nums)
  maxes = [nums[0]]
  max = 0
  1.upto(nums.size - 1) do |i|
    max = maxes[i-2] if i >= 2 && max < maxes[i-2]
    maxes[i] = [max + nums[i], nums[i]].max
  end
  maxes.max || 0
end
```
