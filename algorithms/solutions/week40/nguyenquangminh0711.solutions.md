## Problem 1

It's an easy one. The only tricky part is that because the problem prevents us from creating new array, we need to go backward, starting from m and n and use nums1 as the buffer.

```ruby
# @param {Integer[]} nums1
# @param {Integer} m
# @param {Integer[]} nums2
# @param {Integer} n
# @return {Void} Do not return anything, modify nums1 in-place instead.
def merge(nums1, m, nums2, n)
    k = (m + n)
    while (m > 0 || n > 0)
        k -= 1
        if n <= 0
            nums1[k] = nums1[m - 1]
            m -= 1
        elsif m <= 0
            nums1[k] = nums2[n - 1]
            n -= 1
        elsif nums1[m - 1] < nums2[n - 1]
            nums1[k] = nums2[n - 1]
            n -= 1
        else
            nums1[k] = nums1[m - 1]
            m -= 1
        end
    end
    nums1
end
```
