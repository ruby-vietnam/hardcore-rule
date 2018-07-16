# Problem 1: Median of Two Sorted Arrays

https://leetcode.com/problems/median-of-two-sorted-arrays/description/

```
Runtime: 92 ms
Your runtime beats 25.97 % of ruby submissions.
```

```ruby
# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Float}
def find_median_sorted_arrays(nums1, nums2)
  median_index = (nums1.length + nums2.length - 1) / 2.0
  i = -1
  l1 = 0
  l2 = 0
  r1 = nums1.length - 1
  r2 = nums2.length - 1
  arr = []
  last_steps = 0
  while i <= median_index.floor
    if l1 > nums1.length - 1
      arr = temp_array(nums2, l2, -1, i, median_index, arr)
      i = nums1.length + nums2.length - 1
      break
    end
    if l2 > nums2.length - 1
      arr = temp_array(nums1, l1, -1, i, median_index, arr)
      i = nums1.length + nums2.length - 1
      break
    end
    if nums1[l1] < nums2[l2]
      last_steps = find_max_of_min_point(nums1, l1, r1, nums2[l2])
      arr = temp_array(nums1, l1, last_steps, i, median_index, arr)
      i += last_steps - l1 + 1
      l1 = last_steps + 1
    else
      last_steps = find_max_of_min_point(nums2, l2, r2, nums1[l1])
      arr = temp_array(nums2, l2, last_steps, i, median_index, arr)
      i += last_steps - l2 + 1
      l2 = last_steps + 1
    end
  end
  median_index = i - median_index
  len_arr = arr.length
  if median_index >= 0
    (arr[arr.length.pred - median_index.floor] + arr[arr.length.pred - median_index.ceil]) / 2.0
  else
    0
  end
end
def temp_array(array,l , r, i, median_index, temp_arr)
  if array[l..r].length == 1 || i == median_index.floor
    temp_arr + array[l..r]
  else
    array[l..r]
  end
end
def find_max_of_min_point(array, l, r, point)
  while(l < r - 1)
    m = (l + r) / 2
    if array[m] > point
      r = m
    else
      l = m
    end
  end
  l
end
```
