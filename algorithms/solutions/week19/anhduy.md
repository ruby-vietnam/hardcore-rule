# 461

```c
int hammingDistance(int x, int y) {
  int b = x ^ y;
  int count = 0;
  while (b != 0) {
    count++;
    b = b & (b - 1);

  }
  return count;
}
```
