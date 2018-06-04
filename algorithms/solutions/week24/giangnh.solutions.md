# Problem 1

```python
class Solution(object):
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        for i in range(int(math.sqrt(c)) + 1):
            if math.sqrt(c - i*i).is_integer():
                return True
        return False
```
