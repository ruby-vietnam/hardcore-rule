# Problem 1

```rb
def contains_nearby_duplicate(nums, k)
  cache = {}

  nums.each_with_index do |num, i|
    if cache.has_key?(num) && i - cache[num] <= k
      return true
    else
      cache[num] = i
    end
  end

  false
end
```
