## Problem 1
https://www.hackerrank.com/challenges/mini-max-sum/problem

```
#!/bin/ruby

require 'json'
require 'stringio'

# Complete the miniMaxSum function below.
def miniMaxSum(arr)
    min = arr.min
    max = arr.max
    sum = arr.sum
    print sum - max
    print " "
    print sum - min

end

arr = gets.rstrip.split(' ').map(&:to_i)

miniMaxSum arr
```
