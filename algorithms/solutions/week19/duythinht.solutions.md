### Problem 1

https://leetcode.com/problems/hamming-distance/description/

```C
int ones_count(int x) {
    return x > 0? (x & 1) + ones_count(x >> 1) : 0;
}

int hammingDistance(int x, int y) {
    return ones_count(x ^ y);
}
```
