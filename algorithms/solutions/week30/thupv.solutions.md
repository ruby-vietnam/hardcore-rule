## Problem 1
Link: https://www.hackerrank.com/challenges/mini-max-sum

 * 14 / 14 test cases passed.
 * Status: Accepted

```ruby
#!/bin/ruby

require 'json'
require 'stringio'

# Complete the miniMaxSum function below.
def miniMaxSum(arr)
    max = arr[0]
    min = arr[0]
    sum = arr[0]
    (1..arr.length-1).each do |i|
        max = arr[i] if arr[i] > max
        min = arr[i] if arr[i] < min
        sum += arr[i]
    end
    puts (sum-max).to_s + ' ' + (sum-min).to_s
end

arr = gets.rstrip.split(' ').map(&:to_i)

miniMaxSum arr
```
