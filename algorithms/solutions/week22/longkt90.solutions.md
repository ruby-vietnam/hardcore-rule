### Prolem 1 - [Majority Element](https://leetcode.com/problems/majority-element/description/)

Status:
```
  ✔ Accepted
  ✔ 44/44 cases passed (56 ms)
```

```ruby
def majority_element(nums)
  count_hash = {}
  size = nums.size
  nums.each do |e|
    count_hash[e] = count_hash[e].to_i + 1
    return e if count_hash[e] > size / 2
  end
end
```

### Problem 3 - [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)

Status:
```
  ✔ Accepted
  ✔ 2080/2080 cases passed (80 ms)
```

Code:
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
  merge_array = merge_two_sorted_array(nums1, nums2)
  size = merge_array.size
  return 0 if size.zero?
  if size.even?
    (merge_array[size / 2 - 1] + merge_array[size / 2]) / 2.0
  else
    merge_array[size / 2]
  end
end
```
