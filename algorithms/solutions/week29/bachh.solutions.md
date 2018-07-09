#problem1
```cpp
#include <bits/stdc++.h>

using namespace std;

using namespace std;
class Solution {
public:
  string countAndSay(int z){
    string p = "1";
    string n = "";
    while(--z){
        n="";
      int i=0, j=0;
      while(i < p.size()){
        j=i;
        while(p[i] == p[j] && j < p.size()){
          j++;
        }
        n += to_string(j-i)+ p[i];
        i=j;
      }
      p=n;
    }
    return p;
  }
};

```
# problem 2
``` cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
  int f, s, g, u, d;
  cin >> f >> s >> g >> u >> d;
  bitset<1000002> bs;
  if (s == g){
    std::cout << 0 << std::endl;
    return 0;
  }
  bs.reset();
  queue<pair<int, int>> qu;
  bs.set(s);
  if (s+u <= f) qu.push(make_pair(1, s+u));
  if (s-d <= f) qu.push(make_pair(1, s-d));
  int step = 0;
  bool flag = false;
  while(!qu.empty()){
    auto p  = qu.front();
    step = p.first;
    s = p.second;
    qu.pop();
    if (bs[s]) continue;
    if (s == g) {
      flag = true;
      break;
    }
    bs.set(s);
    if (s+u <= f) qu.push(make_pair(step+1, s+u));
    if (s-d >0 ) qu.push(make_pair(step+1, s-d));
  }
  if (flag){
    std::cout << step << std::endl;
  } else{
    std::cout << "use the stairs" << std::endl;
  }

  return 0;
}
```
