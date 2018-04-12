## Problem 1

https://leetcode.com/problems/contains-duplicate-ii/description/

Build a hash, group all indexes of the same value; then for each value, loop through the index list, if there exists two sequent indexes which are less than k, return true.

```ruby
# @param {Integer[]} nums
# @param {Integer} k
# @return {Boolean}
def contains_nearby_duplicate(nums, k)
    hash = {}
    nums.each_with_index do |num, index|
        hash[num] ||= []
        hash[num] << index
    end
    hash.each do |_num, indexes|
        next if indexes.length < 2
        i = 1
        while i < indexes.length do
            if indexes[i] - indexes[i-1] <= k
                return true
            end
            i += 1
        end
    end
    false
end
```
