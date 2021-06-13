# Week 4

## Problem 1
https://leetcode.com/problems/merge-sorted-array/

This problem is similar to merge sort when we have to merge two sorted sub-arrays, the different is that in merge sort, we merge two sorted sub-arrays to a third array.

In this problem, we have to merge into first array, which is a bit complex than merge sort. The question is how to move elements from `nums2` to `nums1` without overriding existing elements in `nums1`.

The answer is to shift all valid elements in `nums1` to the right, then we start merge two sorted array into first array `nums1` as normal. Because length of `nums1` is `m+n` so it is never there is a case that an element in `nums1` is lost due to overriding by elements in `nums2`.

```python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        # shift all values of nums1 to the right
        for i in range(m-1, -1, -1):
            nums1[i+n] = nums1[i]
        
        # merging from left to right
        i, j = 0, 0
        k = 0
        while i < m and j < n:
            if nums1[n+i] < nums2[j]:
                nums1[k] = nums1[n+i]
                i += 1
            else:
                nums1[k] = nums2[j]
                j += 1
            k += 1
        # no need to copy remaining of nums1, 
        # if there still remain elements in nums1 then they are in exact positions.
        # copy remaining of nums2
        while j < n:
            nums1[k] = nums2[j]
            j += 1
            k += 1
```
```
59 / 59 test cases passed.
Status: Accepted
Runtime: 32 ms
Memory Usage: 14.4 MB
```

There are an alternative, instead shifting all numbers in nums1 before merging, we can start merging from right to left.

```python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        # merging from right to left
        i, j = m-1, n-1
        k = m+n-1
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1

        # copy remaining of nums2
        while j >= 0:
            nums1[k] = nums2[j]
            j -= 1
            k -= 1
```

Time complexity: O(m+n)

Space complexity: O(1)

## Problem 2
https://leetcode.com/problems/shuffle-an-array

The most difficult part is how to get `shuffle` right.

Even through that there are no specific requirements for it, but to make `shuffle` method high quality, we want to return an *uniform random permutation* array.

One of the method to do that is by random in-place which by swapping `nums[i]` randomly with elements from i to n-1.

Refer to CLRS chaper 5.3 for more information.

```python
class Solution:

    def __init__(self, nums: List[int]):
        self.arr = nums

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        return self.arr
        

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        cp = self.arr.copy()
        # shuffle in place
        n = len(self.arr)
        for i in range(n):
            j = random.randint(i, n-1)
            cp[i], cp[j] = cp[j], cp[i]
        return cp
```
```
10 / 10 test cases passed.
Status: Accepted
Runtime: 320 ms
Memory Usage: 19.4 MB
```

Time complexity: O(n)

Space complexity: O(n) for copying array.

## Problem 3
https://leetcode.com/problems/median-of-two-sorted-arrays

```python
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        total = m + n
        rem = total // 2
        
        # handle empty case
        if m == 0:
            return nums2[rem] if total % 2 == 1 else (nums2[rem-1] + nums2[rem]) / 2
        if n == 0:
            return nums1[rem] if total % 2 == 1 else (nums1[rem-1] + nums1[rem]) / 2
        
        # init BS indicators search
        l1, h1, m1 = 0, m-1, (m-1) // 2
        l2, h2, m2 = 0, n-1, (n-1) // 2
        
        # find median base on last number of left half and first number of right half
        def find_med(left_half_end, right_half_start):
            if total % 2 == 1:
                return right_half_start
            return (left_half_end + right_half_start) / 2
        
        while True:
            if nums1[m1] <= nums2[m2]:
                rem = rem -  len(nums1[l1:m1+1])
                if rem == 0:
                    # nums1[m1] belongs to left half, not necessary ending of left half
                    # nums2[l2] belongs to right half, not necessary start of right half
                    first = nums1[m1] if l2 - 1 < 0 else max(nums1[m1], nums2[l2-1])
                    second = nums2[l2] if m1 + 1 >= m else min(nums1[m1+1], nums2[l2])
                    return find_med(first, second)
                l1, h1, h2 = m1 + 1, min(m1 + rem, h1), min(l2 + rem - 1, h2)
            else:
                rem = rem -  len(nums2[l2:m2+1])
                if rem == 0:
                    first = nums2[m2] if l1 - 1 < 0 else max(nums1[l1-1], nums2[m2])
                    second = nums1[l1] if m2 + 1 >= n else min(nums1[l1], nums2[m2+1])
                    return find_med(first, second)
                l2, h2, h1 = m2 + 1, min(m2 + rem, h2), min(l1 + rem - 1, h1)

            # update mid index
            m1 = l1 + (h1-l1) // 2
            m2 = l2 + (h2-l2) // 2
            
            if l1 >= m:
                # no more elements for first array, return median in second array
                return find_med(max(nums1[m-1], nums2[h2]), nums2[h2+1])
            if l2 >= n:
                # no more elements for second array
                return find_med(max(nums1[h1], nums2[n-1]), nums1[h1+1])
```
```

2094 / 2094 test cases passed.
Status: Accepted
Runtime: 88 ms
Memory Usage: 14.6 MB
```
