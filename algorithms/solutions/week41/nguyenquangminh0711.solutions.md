## Problem 1

https://leetcode.com/problems/single-number/description/

Use xor operator. Two duplicated numbers eliminate themselves. 

```ruby
def single_number(nums)
    nums[1..-1].inject(nums[0], &:^)
end
```
