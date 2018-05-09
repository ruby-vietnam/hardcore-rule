## Problem 1

https://leetcode.com/problems/maximum-product-of-three-numbers/description/

* Solutions
If nums.length <= 6, just find all combination of 3 and find the max.
If nums.length > 6, find 3 min numbers, 3 max numbers, then find combination from 6 found members. This one is to leverage negative numbers. 

The algorithm to find 3 max / min number is insertion sort with limit of 3.

```ruby
# @param {Integer[]} nums
# @return {Integer}
def maximum_product(nums)
    return max(nums) if nums.length < 6
    
    min_nums = []
    max_nums = []
    nums.each do |num|
        insert(num, min_nums) { |a, b| a < b }
        insert(num, max_nums) { |a, b| a > b }
    end
    
    max(min_nums + max_nums)
end

def max(nums)
    max = nil
    nums.combination(3).each do |c|
        max = c[0] * c[1] * c[2] if max.nil? || max < c[0] * c[1] * c[2]
    end
    max
end

def insert(num, arr, &compare)
    n = arr.length - 1
    while n >= 0 && compare.call(num, arr[n]) do
        arr[n+1] = arr[n] if n < 2
        n -= 1
    end
    arr[n+1] = num if n < 2
end
```
