## Problem 1
https://www.hackerrank.com/challenges/mini-max-sum/problem

```ruby
#!/bin/ruby

require 'json'
require 'stringio'

# Complete the miniMaxSum function below.
def miniMaxSum(arr)
    min = arr.reduce(0) {|r,n| r + n}
    max = arr[0]
    (0..arr.length-1).each { |i| 
        sum = arr.each.with_index.reduce(0) { |r, (n, index)|
            r = r + n if index != i
            r
        }
        min = sum if sum < min
        max = sum if sum > max
    }
    print min,' ', max
end

arr = gets.rstrip.split(' ').map(&:to_i)
miniMaxSum arr
```

## Problem 2
https://www.hackerrank.com/challenges/sparse-arrays/problem

```ruby
# Complete the matchingStrings function below.
def matchingStrings(strings, queries)
    count = []
    queries.each { |query|
        count << strings.reduce(0) { |r, string| string == query ? r +1 : r}
    }
    count
end
```
