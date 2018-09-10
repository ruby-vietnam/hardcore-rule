## [Problem 1. Power of Three](https://leetcode.com/problems/power-of-three/description/)

```python
class Solution:
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0: 
            return False
        if n == 1:
            return True
        while n > 1:
            if n % 3 != 0:
                return False 
            else: 
                n = n / 3 
        
        return True
```

