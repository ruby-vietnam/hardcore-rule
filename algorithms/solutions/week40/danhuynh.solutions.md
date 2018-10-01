# Problem 1
```ruby
# @param {Integer[]} nums1
# @param {Integer} m
# @param {Integer[]} nums2
# @param {Integer} n
# @return {Void} Do not return anything, modify nums1 in-place instead.
def merge(nums1, m, nums2, n)
  ret = []
  i = j = 0
  while i < m && j < n
    if nums1[i] < nums2[j]
      ret.push(nums1[i])
      i += 1
    else
      ret.push(nums2[j])
      j += 1
    end
  end

  while i < m
    ret.push(nums1[i])
    i += 1
  end

  while j < n
    ret.push(nums2[j])
    j += 1
  end

  ret.each_with_index do |num, i|
    nums1[i] = num
  end
end
```
