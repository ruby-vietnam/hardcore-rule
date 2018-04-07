## Problem 1

```ruby
def contains_nearby_duplicate(nums, k)
  checker = {}

  nums.each_with_index do |num, index|
    old_index = checker[num]
    if old_index && index - old_index <= k
      return true
    end
    checker[num] = index
  end

  false
end
```
