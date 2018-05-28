```python
class Solution(object):
    def simplifyPath(self, path):        
        results = []
        parts = path.split('/')

        for i in range(0, len(parts)):
            if parts[i] == ".." and len(results) > 0:
                results.pop()
                
            if parts[i] not in [".", "", ".."]:
                results.append(parts[i])
                
        return "/" + "/".join(results)
 ```
