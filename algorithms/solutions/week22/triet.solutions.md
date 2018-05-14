## Problem 1

```ruby
# @param {Integer[]} nums
# @return {Integer}
def majority_element(nums)
  h = {}
  nums.each do |num|
    h[num] = h.has_key?(num) ? h[num] += 1 : 1
  end
  
  h.each do |key, value|
    return key if value > (nums.length / 2)
  end
end
```

## Problem 3

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
