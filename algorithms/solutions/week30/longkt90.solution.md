# Problemm 1: Mini-Max Sum

URL: https://www.hackerrank.com/challenges/mini-max-sum/problem

Status:
```
  ✔ Accepted
```
Codes:
```ruby
#!/bin/ruby

require 'json'
require 'stringio'

# Complete the miniMaxSum function below.
def miniMaxSum(arr)
  # too lazy to loop and calculate sum, min, max
  sum = arr.sum
  min = arr.min
  max = arr.max
  printf "%d %d", *[sum - max, sum - min]
end

arr = gets.rstrip.split(' ').map(&:to_i)

miniMaxSum arr

```

# Problemm 4: Median of Two Sorted Arrays

URL: https://leetcode.com/problems/median-of-two-sorted-arrays/description/

Status:
```
  ✔ Accepted
```
Codes:
```ruby
def merge_two_sorted_array(nums1, nums2)
  total_element = nums1.size + nums2.size
  merge_array = Array.new(total_element)
  i = j = 0
  while i + j < total_element
    if nums1[i].nil?
      return merge_array if nums2[j].nil?
      merge_array[i + j] = nums2[j]
      j += 1
    elsif nums2[j].nil?
      merge_array[i + j] = nums1[i]
      i += 1
    elsif nums1[i] < nums2[j]
      merge_array[i + j] = nums1[i]
      i += 1
    else
      merge_array[i + j] = nums2[j]
      j += 1
    end
  end
  merge_array
end

def find_median_sorted_arrays(nums1, nums2)
  merged_array = merge_two_sorted_array(nums1, nums2)
  size = merged_array.size
  return 0 if size.zero?
  if size.even?
    (merged_array[size / 2 - 1] + merged_array[size / 2]) / 2.0
  else
    merged_array[size / 2]
  end
end
```
