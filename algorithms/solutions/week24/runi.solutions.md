## Problem 1
https://leetcode.com/problems/sum-of-square-numbers/description/

```
class Solution(object):
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        m = {}
        limit = math.sqrt(c)

        for i in range(0, int(limit)+1):
            m[i*i] = True
            if m.has_key(c - i*i):
                return True


        return False
```
