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

# Problem 2

```ruby
def find_peak_element(nums)
  nums.each_with_index do |num, index|
    if index > 0
      if num < nums[index - 1]
        next
      end
    end

    if index < nums.size - 1
      if num < nums[index + 1]
        next
      end
    end

    return index
  end
end
```
