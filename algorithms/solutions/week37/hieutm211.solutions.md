## Problem 1

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) return 0;
        double x = log(n) / log(3) + 0.000000001;
        return pow(3, (int) x) == n;
    }
};
```
