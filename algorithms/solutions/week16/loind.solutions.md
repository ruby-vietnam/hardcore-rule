# Problem 1

```ruby
def contains_nearby_duplicate(nums, k)
  map = {}
  nums.each_with_index do |num, index|
    if map[num].nil?
      map[num] = index
    else
      return true if (index - map[num] <= k)
      map[num] = index
    end
  end
  false
end
```

# Problem 2

```ruby
def find_peak_element(nums)
    i = 0
    n = nums.size - 1
    while i < n
        return i if nums[i] > nums[i+1]
        i += 1
    end
    i
end
```
