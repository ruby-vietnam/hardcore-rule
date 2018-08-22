# Problem 1

```ruby
def rob(nums)
  return 0 if nums.empty?
  sum1 = nums[0]
  sum2 = 0
  i = 1

  while i < nums.size
    temp = [sum1, sum2].max
    sum1 = sum2 + nums[i]
    sum2 = temp
    i += 1
  end
  [sum1, sum2].max
end
```
