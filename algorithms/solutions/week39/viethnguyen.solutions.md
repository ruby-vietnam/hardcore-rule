## [Problem 1. Reverse Integer](https://leetcode.com/problems/reverse-integer/description/)

```python 
class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = 0 
        if x < 0: 
            x = -x 
            sign = 1 
        res = 0 
        while x != 0: 
            remainder = x - int(x/10) * 10 
            x = int(x/10)
            res = res * 10 + remainder
            
        if sign == 1:
            res = -res 
        if res > 2**31-1 or res < -2**31:
            return 0 
        return res
```
