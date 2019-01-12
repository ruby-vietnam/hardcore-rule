## Problem 1 (https://leetcode.com/problems/single-number/description)

```ruby
def single_number(nums)
  2 * nums.uniq.sum - nums.sum
end
```
