## [Problem 1: HackerRank: Mini-Max Sum](https://www.hackerrank.com/challenges/mini-max-sum/problem)

```python
  def miniMaxSum(arr):
      arr.sort()
      total = sum(arr)
      minSum = total - arr[-1]
      maxSum = total - arr[0]
      print(minSum, maxSum)
```

## [Problem 2: HackerRank: Sparse Arrays](https://www.hackerrank.com/challenges/sparse-arrays/problem)

```python
  def matchingStrings(strings, queries):
      # brute force: traverse queries:
      # for each query, check how many strings matched. Append the result into a result array. 
      res = [] 
      for q in queries:
          count = 0 
          for s in strings: 
              if q == s: 
                  count += 1 
          res.append(count)
      return res 
```
## [Problem 4: LeetCode: 4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)

```python 
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        
        # approach: 
        # median of the merge array A[0], A[1], ..., A[n-1] is (A[n/2] + A[n/2-1])/2 if n is even 
        # and A[(n-1)/2] if n is odd. 
        # A brute force solution would be merge two arrays and find the median as above, but it would need O(m+n) time. 
        # I'm thinking of an approach to keep 2 pointers iterating over two arrays to gather numbers until we have half the total number of elements in two arrays. 
        # example: 
        # nums1 = [1,3,5]
        # nums2 = [2,4,6]
        # totallen = 6. 
        # i1 = 0 
        # i2 = 0 
        # nums1[0] = 1 < nums2[0] = 2 --> take nums1[0] = 1 , i1 = 1, current_len = 1
        # nums1[1] = 3 > nums2[0] = 2 --> take nums2[1] = 2, i2 = 1, current_len = 2
        # nums1[1] = 3 < nums2[1] = 4 --> take nums1[1] = 3, i1 = 2, current_len = 3
        # at this point, current_len = 3 = totallen/2 --> able to find median = (max(nums1[i1-1],nums2[i2-1]) + min(nums1[i1],nums2[i2]))/2
        # seems to work, now try to code...
        n1 = len(nums1)
        n2 = len(nums2) 
        total_len = n1 + n2 
        i1 = i2 = 0 # indexes to traverse nums1, nums2 
        current_len = 0 
        max_first_half = 0
        while current_len < int(total_len/2):
            print(current_len, i1, i2, n1, n2)
            if i1 < n1 and i2 < n2: 
                if nums1[i1] < nums2[i2]: 
                    max_first_half = nums1[i1]
                    i1 += 1 
                else: 
                    max_first_half = nums2[i2]
                    i2 += 1 
                current_len += 1 
                continue 
            if i1 < n1: 
                max_first_half = nums1[i1]
                i1 += 1 
                current_len += 1 
            if i2 < n2: 
                max_first_half = nums2[i2]
                i2 += 1 
                current_len += 1 
        print(max_first_half)
        min_second_half = 0 
        if i1 >= n1:
            min_second_half = nums2[i2]
        elif i2 >= n2: 
            min_second_half = nums1[i1]
        else: 
            min_second_half = min(nums1[i1], nums2[i2])
        print(min_second_half)
        median = 0 
        if current_len * 2 == total_len:
            median = (max_first_half + min_second_half)/2
            print("case 1")
        else: 
            print("case 2")
            median = min_second_half
        return median 
        ## passed all the test cases! Even though I think the time complexity is not O(log(m+n)) as the problem suggests
```
