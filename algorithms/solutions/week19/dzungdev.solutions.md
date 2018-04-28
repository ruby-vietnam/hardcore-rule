Problem1: https://leetcode.com/problems/hamming-distance/description/

We can use XOR between x and y, then make the value to binary value, while we loop to make binary value, we can calculate the result if we meet 1

Time Complexity is O(log(n)).

```java
public int hammingDistance(int x, int y) {
    int xor = x ^ y;
    int result = 0;
  while (xor > 0) {
    result += (xor % 2);
    xor /= 2;
  }
  return result;
}
```
