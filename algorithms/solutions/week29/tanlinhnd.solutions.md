# Problem 1: [Count and Say](https://leetcode.com/problems/count-and-say/description/)
```python
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 0:
        	return ""
        result = "1"
        for k in range(1,n,1):
            i = 0
            tmp = ""
            while i<len(result):
                j = i + 1
                while j < len(result):
                    if result[j] != result[i]:
                    	break
                    else:
                    	j+=1
                tmp += (str(j-i) + str(result[i]))
                i = j
            result = tmp[:]
        return result
```
