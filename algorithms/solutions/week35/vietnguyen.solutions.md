## [Problem 2. Spiral matrix III](https://leetcode.com/contest/weekly-contest-97/problems/spiral-matrix-iii/)

```python 
class Solution:
    def spiralMatrixIII(self, R, C, r0, c0):
        """
        :type R: int
        :type C: int
        :type r0: int
        :type c0: int
        :rtype: List[List[int]]
        """
        res = [] 
        cid = 0 
        curC = c0 
        curR = r0
        res.append((curR, curC))
        while len(res) < R * C: 
            # go right 
            for j in range(1, 2 * cid+2):
                curC = curC + 1 
                if 0 <= curC < C and 0 <= curR < R:
                    res.append((curR,curC))
                #print(res)
                
            # go down 
            for i in range(1, 2 * cid+2):
                curR = curR + 1 
                if 0 <= curC < C and 0 <= curR < R:
                    res.append((curR,curC))
                #print(res)
            # go left 
            for j in range(1, 2 * cid+3):
                curC = curC - 1 
                if 0 <= curC < C and 0 <= curR < R:
                    res.append((curR,curC))
                #print(res)
            # go up 
            for i in range(1, 2 * cid+3):
                curR = curR - 1 
                if 0 <= curC < C and 0 <= curR < R:
                    res.append((curR,curC))
                #print(res)
            
            cid += 1 
        return res 
```

