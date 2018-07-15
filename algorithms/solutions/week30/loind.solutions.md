# Problem 1

```ruby
#!/bin/ruby

require 'json'
require 'stringio'

# Complete the miniMaxSum function below.
def miniMaxSum(arr)
  arr.sort!
  max_sum = arr.drop(1).sum
  min_sum = arr.take(4).sum
  puts "#{min_sum} #{max_sum}"
end

arr = gets.rstrip.split(' ').map(&:to_i)

miniMaxSum arr
```
