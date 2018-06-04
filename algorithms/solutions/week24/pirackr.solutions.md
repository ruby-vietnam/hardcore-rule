```python
import math 

class Solution(object):
    def judgeSquareSum(self, c):
        sq = {}
        
        
        for i in range(0,int(math.sqrt(c)) + 1 :
            sq[i*i] = 1
            
            if (c -  i*i) in sq:
                return True
                      
        return False
```
