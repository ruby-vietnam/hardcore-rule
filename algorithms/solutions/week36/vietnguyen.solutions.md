## [Problem 1. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/)

```python
class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        needed = [0] * (n+1)
        for i in range(1, n+1):
            if i == 1:
                needed[i] = 1 
            elif i == 2: 
                needed[i] = 2
            else:
                needed[i] = needed[i-1] + needed[i-2]
        
        return needed[n]
```

