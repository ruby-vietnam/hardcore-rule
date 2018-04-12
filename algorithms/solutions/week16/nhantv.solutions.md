# Problem 1: Contains Duplicate II

https://leetcode.com/problems/contains-duplicate-ii/description/

- Use hash to save index of current number. If current number had index in the hash, we check distance of current number.
After that we return `true` if the distance less or equal the `k` or re-set index of current number.
- Return `false` when we haven't found any distance.

```
Runtime: 48 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {Integer[]} nums
# @param {Integer} k
# @return {Boolean}
def contains_nearby_duplicate(nums, k)
  hash = {}
  nums.each.with_index do |num, i|
    if hash[num]
      return true if i - hash[num] <= k
      hash[num] = i
    else
      hash[num] = i
    end
  end
  false
end
```

# Problem 2: Find Peak Element

https://leetcode.com/problems/find-peak-element/description/

- Use binary index search to find peak

```
Runtime: 40 ms
Your runtime beats 75.00 % of ruby submissions.
```

```ruby
# @param {Integer[]} nums
# @return {Integer}
def find_peak_element(nums)
  min = -(2**(0.size * 8 -2))
  right = nums.length - 1
  left = 0
  while left < right
    mid = (left + right) / 2
    var_left = mid > left ? nums[mid - 1] : min
    var_right = mid < right ? nums[mid + 1] : min
    return mid if nums[mid] > var_left && nums[mid] > var_right
    if var_left > nums[mid]
      right = mid
    else
      left = mid + 1
    end
  end
  left
end
```
