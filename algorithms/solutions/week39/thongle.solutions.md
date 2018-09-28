## Problem 1 - [Reverse Integer](https://leetcode.com/problems/reverse-integer/description/)

```python
def solution(x):
    def sign(i):
        return 1 if i > 0 else -1

    u, v = abs(x), 0
    while u > 0:
        v = v * 10 + u % 10
        u /= 10

    if (-2 ** 3 <= v) and (v <= 2 ** 31 - 1):
        return v * sign(x)
    return 0
```
