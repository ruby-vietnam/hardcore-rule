# Problem 1: 461 - Hamming Distance

Status:
```
  ✔ Accepted
  ✔ 149/149 cases passed (4 ms)
  ✔ Your runtime beats 20.7 % of c submissions
```

```c
int hammingDistance(int x, int y) {
  int distance = 0;
  int val = x ^ y;
  while (val != 0) {
    val &= val - 1;
    distance++;
  }
  return distance;
}
```
