# Problem 1

```rb
def find_lhs(nums)
  return 0 if nums == []

  cache = {}

  nums.each do |num|
    if cache.has_key?(num)
      cache[num] += 1
    else
      cache[num] = 1
    end
  end

  max = 0

  cache.each do |k, v|
    if cache.has_key?(k - 1)
      max = [max, v + cache[k - 1]].max
    else
      next
    end
  end

  max
end
```
