# Problem 1

```ruby
def check_possibility(nums)
  count = 0
  l = 0
  r = nums.size - 1

  while l < r
    if nums[l] <= nums[r]
      l += 1
      r -= 1
    else
      count += 1
    end
    return false if count > 1
  end
  true
end
```
