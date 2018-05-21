# Problem 1: Majority Element

```python

from collections import defaultdict

class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        freq = defaultdict(int)
        for item in nums:
            freq[item] += 1
        major_element = filter(lambda item: item[1] > len(nums)/2, freq.items())
        return int(list(dict(major_element).keys())[0])
```
