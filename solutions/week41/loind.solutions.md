# Problem 1

```ruby
def single_number(nums)
  res = nums[0]
  i = 1
  while i < nums.size
    res = res ^ nums[i]
    i += 1;
  end
  res
end
```
