# Week 24

## Problem 4 - [QMAX - Giá trị lớn nhất] (http://vn.spoj.com/problems/QMAX)

```cpp
//QMAX
#include <iostream>
#define maxn 50021
using namespace std;

long a[maxn], value[4*maxn], s, f, res;

void getmax(long u, long v, long pos) {
  if ((u > f) || (v < s)) return;
  if ((u >= s) && (v <= f)) {
    res = max(res, value[pos]);
    return;
  }
  long mid = (u + v)/2;
  getmax(u, mid, 2*pos);
  getmax(mid + 1, v, 2*pos + 1);
}

void update(long u, long v, long pos) {
  if (u == v) {
    value[pos] = a[u];
    return;
  }
  long mid = (u + v)/2;
  update(u, mid, 2*pos);
  update(mid + 1, v, 2*pos + 1);
  value[pos] = max(value[2*pos], value[2*pos + 1]);
}

int main() {
  long n, m, q, u, v, k;
  scanf("%d%d", &n, &m);
  for (long i = 1; i <= n; i++) a[i] = 0;
  for (long i = 1; i <= m; i++) {
    scanf("%d%d%d", &u, &v, &k);
    a[u] += k; a[v + 1] -= k;
  }
  for (long i = 2; i <= n; i++) a[i] = a[i] + a[i - 1];
  update(1, n, 1);
  scanf("%d", &q);
  for (long i = 1; i <= q; i++) {
    scanf("%d%d", &s, &f);
    res = 0; getmax(1, n, 1);
    printf("\n%d", res);
  }
  return 0;
}
```
