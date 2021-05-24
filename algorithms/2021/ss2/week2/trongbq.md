# 2021 - SS2 - Week 2

## Problem 1
https://leetcode.com/problems/add-binary/

Start from right to left, with each character of two string, we add them up along with remember value from previous add operation.

One string might be longer than the other, so we use two iterator for two string separately, when we finish calculation for common substring, we add remaining of the longer string to final result.

Because add binary opration circle around 0 and 1 so we can use modulo to calculate final value of each pair character, and update rememer value as well.

```python
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # add two binary character along with remember value
        # 0 + 0 with 0 => 0, 0
        # 0 + 1 with 0 => 1, 0
        # 0 + 1 with 1 => 0, 1
        # 1 + 1 with 1 => 1, 1
        def add_bin(*args):
            s = sum([int(c) for c in args])
            return s % 2, 1 if s >= 2 else 0
        
        # start from right to left, doing add operation on each character of both string
        remember = 0
        result = []  # Python string is immutable so use list as a immediate data storage
        ai, bi = len(a) - 1, len(b) - 1
        while ai != -1 and bi != -1:
            temp, remember = add_bin(a[ai], b[bi], remember)
            result.append(temp)
            ai, bi = ai - 1, bi - 1
            
        # add remaining of longer string
        while ai != -1:
            temp, remember = add_bin(a[ai], remember)
            result.append(temp)
            ai -= 1
        while bi != -1:
            temp, remember = add_bin(b[bi], remember)
            result.append(temp)
            bi -= 1
        
        # need to add remember value if we have it
        if remember == 1:
            result.append(1)
            
        return ''.join([str(i) for i in reversed(result)])
```  
```
294 / 294 test cases passed.
Status: Accepted
Runtime: 36 ms
Memory Usage: 14.3 MB
```

Time complexity: O(n) with n is length of longest string.

Space complexity: O(n) for temporary array result.

There is also a different approach which uses bitwise operator instead of add opration.


```python
class Solution:
    def addBinary(self, a: str, b: str) -> str:        
        # start from right to left, doing add operation on each character of both string
        remember = 0
        result = []  # Python string is immutable so use list as a immediate data storage
        ai, bi = len(a) - 1, len(b) - 1
        while ai != -1 and bi != -1:
            aint, bint = int(a[ai]), int(b[bi])
            result.append(aint ^ bint ^ remember)
            remember = (aint and bint) | (aint & remember) | (bint & remember)
            ai, bi = ai - 1, bi - 1
            
        # add remaining of longer string
        while ai != -1:
            temp, remember = int(a[ai]) ^ remember,int(a[ai]) & remember
            result.append(temp)
            ai -= 1
        while bi != -1:
            temp, remember = int(b[bi]) ^ remember, int(b[bi]) & remember
            result.append(temp)
            bi -= 1
        
        # need to add remember value if we have it
        if remember == 1:
            result.append(1)
            
        return ''.join([str(i) for i in reversed(result)])
```     
