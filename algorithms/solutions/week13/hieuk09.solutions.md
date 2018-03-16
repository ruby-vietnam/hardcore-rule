## Problem 1

```ruby
def maximum_product(nums)
  max_1 = max_2 = max_3 = -9999
  min_1 = min_2 = 9999
  nums.each do |num|
    if max_1 < num
      max_3 = max_2
      max_2 = max_1
      max_1 = num
    elsif max_2 < num
      max_3 = max_2
      max_2 = num
    elsif max_3 < num
      max_3 = num
    end

    if num < min_1
      min_2 = min_1
      min_1 = num
    elsif num < min_2
      min_2 = num
    end
  end

  [max_1 * max_2 * max_3, max_1 * min_1 * min_2].max
end
```
