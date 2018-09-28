# [Problem 1. Merge Sorted Arrays](https://leetcode.com/problems/merge-sorted-array/description/)

```python 
class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        i,j = 0,0
        remain_m, remain_n = m,n
        while remain_m > 0 and remain_n > 0:
            if nums1[i] <= nums2[j]:
                i+=1 
                remain_m-=1
            else:
                nums1[i+1:m+n] = nums1[i:m+n-1]
                nums1[i] = nums2[j]
                i+=1
                j+=1 
                remain_n-=1 
        if remain_n > 0:
            nums1[i:m+n] = nums2[j:n]
```
