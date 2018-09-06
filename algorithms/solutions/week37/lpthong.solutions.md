## Problem 1 - [Power of Three](https://leetcode.com/problems/power-of-three/description/)

 ```python
 def solution(n):
     if n == 0:
         return False
     if n == 1:
         return True
     x = 1
     while x < n:
         x *= 3
     return x == n
 ```
