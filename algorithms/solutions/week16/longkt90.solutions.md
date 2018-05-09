## Problem 1

```ruby
def contains_nearby_duplicate(nums, k)
  tmp_hash = {}
  last_index = nums.size - 1
  (0..last_index).each do |i|
    return true if !tmp_hash[nums[i]].nil? && i - tmp_hash[nums[i]] <= k
    tmp_hash[nums[i]] = i
  end
  false
end
```
