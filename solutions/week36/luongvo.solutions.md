# Week 36

## Problem 1

```python
class Solution(object):
    def climbStairs(self, n):
        a, b = 0, 1
        for i in range(n + 1): a, b = b, a + b
        return a
```

> 
45 / 45 test cases passed.
Status: Accepted
Runtime: 52 ms
Submitted: 1 minute ago
