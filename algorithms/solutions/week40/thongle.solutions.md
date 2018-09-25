## Problem 1 - [Perfect Squares](https://leetcode.com/problems/perfect-squares/description/)
```python
def solution(n):
  from math import sqrt

  f, i = [0], 1
  while (i <= n):
      mn, f_len = 2 ** 31 - 1, f.__len__()
      for j in range(1, int(sqrt(i)) + 1):
          mn = min(mn, f[-j * j] + 1 if (j * j < f_len) else 1)
      f.append(mn)
      i += 1
  return f[n]
```
