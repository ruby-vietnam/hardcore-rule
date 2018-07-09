# Problem 1

```python
class Solution:
    
    def countAndSay(self, n):
        value = 1
        for i in range(n - 1):
            value = self.read_value(str(value))
        return str(value)
    
    def read_value(self, value):
        current = None
        count = 0
        result = ''
        for ch in value:
            if ch != current:
                if current is not None:
                    result = result + '{0}{1}'.format(count, current)
                current = ch
                count = 1
            else:
                count += 1
        result = result + '{0}{1}'.format(count, current)        
        return result
```