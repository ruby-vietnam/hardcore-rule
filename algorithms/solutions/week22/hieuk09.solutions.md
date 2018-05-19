## Problem 1

```ruby
def majority_element(nums)
  counter = Hash.new { 0 }
  majority_size = nums.size / 2 + 1
  nums.each do |num|
    counter[num] += 1

    if counter[num] >= majority_size
      return num
    end
  end
end
```
