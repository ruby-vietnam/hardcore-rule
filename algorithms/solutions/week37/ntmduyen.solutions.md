# Problem 1 - [Power of Three](https://leetcode.com/problems/power-of-three/description/)

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1) == 0;
    }
};
```
