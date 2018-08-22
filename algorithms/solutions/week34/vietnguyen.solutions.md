## [Problem 1. House Robber](https://leetcode.com/problems/house-robber/description/)

```python
class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0 
        max_up_to = [0] * n 
        max_up_to[0] = nums[0] 
        for i in range(1,n):
            max_up_to[i] = max(max_up_to[i-1], max_up_to[i-2] + nums[i])
        return max_up_to[n-1]
```
