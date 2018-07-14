## Problem 1

```ruby
def miniMaxSum(arr)
  sum = arr.sum
  min = arr.min
  max = arr.max

  puts "#{sum - max} #{sum - min}"
end
```
