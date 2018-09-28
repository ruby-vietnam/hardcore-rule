# Problem 1: Merge Sorted Array

https://leetcode.com/problems/merge-sorted-array/description/#

```
Runtime: 44 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {Integer[]} nums1
# @param {Integer} m
# @param {Integer[]} nums2
# @param {Integer} n
# @return {Void} Do not return anything, modify nums1 in-place instead.
def merge(nums1, m, nums2, n)
  i1 = m - 1
  i2 = n - 1
  (m + n - 1).downto(0) do |i|
    if i2 < 0
      nums1[0..i] = nums1[0..i1]
      break
    end
    if i1 < 0
      nums1[0..i] = nums2[0..i2]
      break
    end
    if nums1[i1] >= nums2[i2]
      nums1[i] = nums1[i1]
      i1 -= 1
    else
      nums1[i] = nums2[i2]
      i2 -= 1
    end
  end
  nums1
end
```
