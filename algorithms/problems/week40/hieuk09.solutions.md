## Problem 1

```ruby
def merge(nums1, m, nums2, n)
  index = m + n - 1

  while index >= 0
    if m <= 0
      nums1[index] = nums2[n - 1]
      n -= 1
    elsif n <= 0
      nums1[index] = nums1[m - 1]
      m -= 1
    elsif nums1[m - 1] > nums2[n - 1]
      nums1[index] = nums1[m - 1]
      m -= 1
    else
      nums1[index] = nums2[n - 1]
      n -= 1
    end

    index -= 1
  end
end

```
