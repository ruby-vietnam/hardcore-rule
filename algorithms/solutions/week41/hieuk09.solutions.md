## Problem 1

```ruby
def single_number(nums)
  nums.inject(0) { |result, num| result ^ num }
end
```
