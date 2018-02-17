## Problem 1

```ruby
def find_lhs(nums)
  hash = Hash.new(0)

  nums.each do |n|
    hash[n] += 1
  end

  max = 0
  list = hash.keys.sort

  (list.length - 1).times do |i|
    n1 = list[i]
    n2 = list[i + 1]
    if n2 - n1 == 1 && hash[n2] + hash[n1] > max
      max = hash[n2] + hash[n1]
    end
  end

  max
end
```
