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

## [Problem 2. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_len = 0
        i,j = 0,0
        current_set = set()
        # edge case 
        if len(s) == 1:
            return 1 
        while j < len(s):
            if s[j] in current_set:
                max_len = max(max_len, j-i)
                # remove elements until an element similar to s[j] 
                while s[i] != s[j]:
                    current_set.remove(s[i])
                    i += 1
                current_set.remove(s[i])
                i += 1 
            max_len = max(max_len, j - i+1)
            current_set.add(s[j])
            j += 1 
        return max_len 
```
