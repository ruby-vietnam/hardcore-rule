### Prolem 1 - [Count and Say](https://leetcode.com/problems/count-and-say/description/)
```cpp
class Solution {
public:
  string countAndSay(int n) {
    string s = "1";
    for (int i = 1; i < n; ++i) {
      int cnt = 0;
      string tmp = "";
      for (int j = 0; j <= s.size(); ++j) {
        if (j == s.size() || (j > 0 && s[j] != s[j - 1])) {
          cout << cnt << endl;
          tmp += to_string(cnt);
          tmp.push_back(s[j - 1]);
          cnt = 1;
        } else ++cnt;
      }
      s = tmp;
    }
    return s;
  }
};
```

### Prolem 2 - [Elevator Trouble](https://www.spoj.com/problems/ELEVTRBL/)
```cpp
#include<iostream>
#include<queue>
using namespace std;
int v[1000000] = { 0 };
queue<int> q;
int main() {
  ios::sync_with_stdio(false);
  int f, s, g, u, d, cur;
  cin >> f >> s >> g >> u >> d;
  q.push(s); v[s] = 1;
  while (!q.empty()) {
    cur = q.front();
    if (cur == g) break;
    q.pop();
    if (cur + u <= f && v[cur + u] == 0)
      v[cur + u] = v[cur] + 1, q.push(cur + u);
    if (cur - d >= 1 && v[cur - d] == 0)
      v[cur - d] = v[cur] + 1, q.push(cur - d);
  }
  if (cur == g) cout << v[g] - 1;
  else cout << "use the stairs";
  return 0;
} 
```

### Problem 3 - [Minimize the error](http://codeforces.com/problemset/problem/960/B)
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N=1003;

priority_queue<int> q;
typedef long long ll;
ll res;
int a[N],b[N],k,k1,n;

int main() {
  //freopen("input.txt","r",stdin);
  scanf("%d%d%d",&n,&k,&k1);
  k+=k1;
  for (int i=0; i < n; ++i) scanf("%d",&a[i]);
  for (int i=0; i < n; ++i) {
    scanf("%d",&b[i]);
    q.push(abs(a[i]-b[i]));
  }
  while (k) {
    int t=q.top();
    q.pop();
    q.push(abs(--t));
    --k;
  }
  while(!q.empty()){
    int t=q.top();
    res += 1LL*t*t;
    q.pop();
  }
  cout << res;
}
```

### Problem 4 - [Stone Piles](https://www.hackerrank.com/challenges/stone-piles/problem)
```cpp
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
set<int> s[55];

int n,f[55],T;
bool avail[55];

int main() {
  memset(f,-1,sizeof f);
  f[0] = 0;
  avail[0] = 1;
  for(int i = 1; i <= 50; ++i){
    f[i] = 0;
    while(s[i].count(f[i]))++f[i];
    for(int j = 50; j >= i; --j) if(avail[j-i]){
      avail[j] = 1;
      for(set<int>::iterator it = s[j-i].begin(); it != s[j-i].end(); ++it)
        s[j].insert((*it)^f[i]);
    }
    s[i].insert(f[i]);
  }
  scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    int a,res = 0;
    for(int i = 0; i < n; ++i) {
      scanf("%d",&a);
      res^=f[a];
    }
    if(res>0)puts("ALICE");
    else puts("BOB");
  }
}
```

