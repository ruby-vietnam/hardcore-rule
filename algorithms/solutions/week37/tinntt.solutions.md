## Problem 1: [Power Of Three](https://leetcode.com/problems/power-of-three/description/)

 ```java
class Solution {
    boolean isPowerOfThree(int n) {
        return Integer.toString(n, 3).matches("^10*$");
    }
}
```