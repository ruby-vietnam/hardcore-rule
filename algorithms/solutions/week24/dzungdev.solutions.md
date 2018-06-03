Problem1: https://leetcode.com/problems/sum-of-square-numbers/description/

We loop a from 0 and check whether a * a < c or not, if yes, then calculate b, if there is b, then return true.

Please take note that we need a is long type as if it is int then a * a can be negative value.

Time complexity is O(sqrt(c) * logc)
Space complexity is O(1)


```java
public boolean judgeSquareSum(int c) {
        for (long a = 0; a * a <= c;a++) {
          double b = Math.sqrt(c - a * a);
          if (b == (int) b) return true;
        }
      return false;
    }
```
