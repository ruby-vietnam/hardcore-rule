
# Problem 1
#### [Majority Element](https://leetcode.com/problems/majority-element/)

```python
from collections import Counter

class Solution:
    def majorityElement(self, nums):
        return Counter(nums).most_common(1)[0][0]
```
