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

## Problem 4

```ruby
# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Float}
def find_median_sorted_arrays(nums1, nums2)
  merged = []
  l1, l2 = 0, 0
  until l1 >= nums1.length && l2 >= nums2.length do
    if l1 >= nums1.length 
      merged << nums2[l2]
      l2 += 1
      next
    end
    
    if l2 >= nums2.length
      merged << nums1[l1]
      l1 += 1
      next
    end
      
    if nums1[l1] < nums2[l2]
      merged << nums1[l1]
      l1 +=1
    else
      merged << nums2[l2]
      l2 += 1
    end
  end
  
  if merged.length % 2 == 0 
    (merged[merged.length / 2] + merged[merged.length / 2 - 1]) / 2.0
  else
    merged[merged.length / 2]*1.0
  end
end
```
