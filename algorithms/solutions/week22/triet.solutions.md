## Problem 1

```ruby
# @param {Integer[]} nums
# @return {Integer}
def majority_element(nums)
  h = {}
  nums.each do |num|
    h[num] = h.has_key?(num) ? h[num] += 1 : 1
  end
  
  h.each do |key, value|
    return key if value > (nums.length / 2)
  end
end
```
