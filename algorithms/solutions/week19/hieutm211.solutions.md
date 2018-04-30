##Problem 1

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0, tmp = x ^ y;
        for (int i = 0; i < 32; ++i) ans += (tmp >> i) & 1;
        return ans;
    }
};
```
