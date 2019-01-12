## Problem 1

```ruby
# @param {Integer[]} nums
# @return {Integer}
def single_number(nums)
    nums.reduce (0) { |n, r| r = r ^ n }
end
```
