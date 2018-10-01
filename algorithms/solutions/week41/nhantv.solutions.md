# Problem 1: Single Number

https://leetcode.com/problems/single-number/description/

```
Runtime: 52 ms
Your runtime beats 90.28 % of ruby submissions.
```

```ruby
# @param {Integer[]} nums
# @return {Integer}
def single_number(nums)
  (nums.length - 1).times do |i|
    nums[0] ^= nums[i + 1]
  end
  nums[0]
end
```
