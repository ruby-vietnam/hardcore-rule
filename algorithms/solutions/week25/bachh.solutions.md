# Problem 2
```cpp
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:

  vector<int> parent;

  int findGroup(int a){
    if(parent[a] == a) return a;
    else return findGroup(parent[a]);
  }

  void joinGroup(int a, int b){
    int pa = findGroup(a);
    int pb = findGroup(b);
    parent[pa] = pb;
  }

  int findCircleNum(vector<vector<int>>& M) {
    parent = vector<int>(M.size());
    for (int i = 0; i < (int)M.size(); ++i) {
      parent[i] = i;
    }
    for (int i = 0; i < (int)M.size(); ++i) {
      for (int j = 0; j < (int) M[0].size(); ++j) {
        if(M[i][j] == 1){
          joinGroup(i, j);
        }
      }
    }
    int counter = 0;
    for (int i = 0; i < (int)M.size(); ++i) {
      counter += (parent[i] == i);
    }
    return counter;
  }
};
```

# Problem 3
### Idea: The to get the first one, either by gcd a whole array or a subset of the array.
### Min step = min length of subarray + length of whole array - 1
```cpp
#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
int gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
int lcm(ll a, ll b) { ll i=(a/gcd(a,b))*b; assert(i>0); return i; }
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

//  ***** MAIN *****
int main(){
  //ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int v[2000];
  int g;

  int ones = 0;

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    ones += (v[i] == 1);
  }

  if(n==1 && v[0] == 1 ){
    std::cout << 0 << std::endl;
    return 0;
  }

  int minDistance = 3001;

  for (int i = 0; i < n; ++i) {
    g = v[i];
    int j = i+1;
    while(j < n ){
      g = gcd(g, v[j]);
      if(g==1){
        minDistance = min(minDistance, j - i);
        break;
      }
      j++;
    }
    //std::cout << i << "|" << j << "|" << minDistance << std::endl;
  }

  if(minDistance >= 2011){
    std::cout << -1 << std::endl;
  }
  else {
    std::cout << minDistance + ( n - ones ) - 1 << std::endl;
  }

  return 0;
}
```

