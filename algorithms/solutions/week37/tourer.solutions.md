# Problem 1

## [Power of Three](https://leetcode.com/problems/power-of-three/description/)
```java
class Solution {
    public boolean isPowerOfThree(int n) {
        int d = n;
        while(d % 3 == 0 && d > 1) {
            d /= 3;
        }
        return d == 1;
    }
}
```
