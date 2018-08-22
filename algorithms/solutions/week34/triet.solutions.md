## Problem 1

```ruby
def rob(nums)
  mem = Array.new(nums.length, -1)
  r(nums, nums.length - 1, mem)
end

def r(nums, i, mem)
  return 0 if i.negative?
  return mem[i] if mem[i] > -1

  mem[i] = [r(nums, i - 2, mem) + nums[i], r(nums, i - 1, mem)].max
end
```
