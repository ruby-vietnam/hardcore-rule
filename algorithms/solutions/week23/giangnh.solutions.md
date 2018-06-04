#Problem2

```python
class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        sp, st = path.split('/'), []

        for i in sp:
            if i == '..':
                if st:
                    st.pop()

            elif i != '' and i != '.':
                st.append(i)

        return '/' + '/'.join(st)
```
