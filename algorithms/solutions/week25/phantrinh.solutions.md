### Prolem 1 - [Keyboard Row](https://leetcode.com/problems/keyboard-row/description/)

Runtime: 30 ms

```python
class Solution(object):
    def findWords(self, words):
        ret = []
        f = {'q' : 0, 'w' : 0, 'e' : 0, 'r' : 0, 't' : 0, 'y' : 0, 'u' : 0, 'i' : 0, 'o' : 0, 'p' : 0}
        f.update({'a' : 1, 's' : 1, 'd' : 1, 'g' : 1, 'h' :  1, 'j' : 1, 'k' : 1, 'l' : 1})
        f.update({'z' : 2, 'x' : 2, 'c' : 2, 'v' : 2, 'b' : 2, 'n' : 2, 'm' : 2})
        for word in words:
            w = word.lower()
            cnt = [0, 0, 0]
            for c in w:
                try:
                    cnt[f[c]] = 1
                except:
                    pass
            if sum(cnt) == 1:
                ret.append(word)
        return ret
```

### Prolem 2 - [Friend Circles](https://leetcode.com/problems/friend-circles/description/)

Runtime: 146 ms

```python
class Solution(object):
    def find(self, u, p):
        if u == p[u]:
            return u
        p[u] = self.find(p[u], p)
        return p[u]
    
    def unite(self, u, v, p, cnt):
        u = self.find(u, p)
        v = self.find(v, p)
        if u == v:
            return cnt
        p[v] = u
        return cnt - 1
    
    def findCircleNum(self, M):
        cnt = len(M)
        p = [i for i in range(cnt)]
        for i in range(len(M)):
            for j in range(len(M[i])):
                if M[i][j] == 1:
                    cnt = self.unite(i, j, p, cnt)
        return cnt
```

### Problem 3 - [Pride](http://codeforces.com/contest/892/problem/C)

Runtime: 1028 ms

Code:
```python
from fractions import gcd

n = int(input())
a = [int(x) for x in raw_input().split()]

one = 0
for i in range(n):
    if a[i] == 1:
        one += 1
if one > 0:
    print n - one
    quit()
res = n + 1
for i in range(n):
    cur = a[i]
    for j in range(i , n):
        cur = gcd(cur , a[j])
        if cur == 1:
            res = min(res , j - i + 1)
            break
if res == n + 1:
    print -1
else:
    print res + n - 2
```

### Problem 4 - [QMAX](http://vn.spoj.com/problems/QMAX/)

Runtime: 60 ms

Code:
```cpp
#include<bits/stdc++.h>
using namespace std;
 
int n, m, p, u, v, w;
int it[4*50005],a[50005];
 
void build(int id, int l, int r) {
    if(l == r) it[id] = a[l];
    else {
        int m = (l + r)>>1, x = id<<1;
        build(x,l,m);
        build(x+1,m+1,r);
        it[id] = max(it[x],it[x+1]);
    }
}
 
int findMax(int id, int l, int r, int u, int v) {
    if(v < l || u > r) return INT_MIN;
    if(u <= l && v >= r) return it[id];
    int m = (l + r)>>1, x = id<<1;
    return max(findMax(x,l,m,u,v),findMax(x+1,m+1,r,u,v));
}
 
int main() {
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d",&u,&v,&w);
        a[u] += w;
        a[v+1] -= w;
    }
    for(int i = 1; i <= n; ++i) a[i]+=a[i-1];
    build(1,1,n);
    scanf("%d",&p);
    for(int i = 0; i < p; ++i) {
        scanf("%d%d",&u,&v);
        printf("%d\n",findMax(1,1,n,u,v));
    }
}
```