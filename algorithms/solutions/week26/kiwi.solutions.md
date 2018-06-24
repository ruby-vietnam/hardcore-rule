### Problem 1

```python
from  collections import defaultdict

class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        dict_small = defaultdict(int)
        for x in s:
            dict_small[x] += 1
        for y in t:
            if (dict_small[y] == 0):
                return y
            else:
                dict_small[y] -= 1
```
