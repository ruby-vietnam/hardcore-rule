## Problem 1

https://leetcode.com/problems/majority-element/description/

```ruby
def majority_element(nums)
    hash = {}
    nums.each do |num|
        hash[num] ||= 0
        hash[num] += 1
        return num if hash[num] > nums.length / 2
    end
end
```
