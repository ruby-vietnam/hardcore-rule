## Problem 1

```c++
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  long long int f[18][10];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < k; ++j) {
      if (i == 0)
        if (j == 0)
          f[i][j] = 0;
        else
          f[i][j] = 1;
      else
        if (j == 0) {
          f[i][j] = 0;
          for (int l = 1; l < k; ++l) f[i][j] += f[i-1][l];
        }
        else {
          f[i][j] = 0;
          for (int l = 0; l < k; ++l) f[i][j] += f[i-1][l];
        }
    }
  long long int result = 0;
  for (int i = 0; i < k; ++i) result += f[n-1][i];
  cout << result;
  return 0;
}
```

## Problem 2
```c++
#define pii pair<int, int>
#define vi vector<int>

class Solution {
private: 
  bool inside(int R, int C, int r0, int c0) {
    if (r0 < 0 || r0 >= R) return false;
    if (c0 < 0 || c0 >= C) return false;
    return true;
  }
  
  int previousK(int k) {
    if (k)
      return k - 1;
    else
      return 3;
  }
  
public:
  vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int count = 0, k = 0;
    set<pii> visited;
    vector<vi> results;
    
    while (count < R * C) {
      visited.insert(pii(r0, c0));
      if (inside(R, C, r0, c0)) {
        results.push_back(vi {r0, c0});
        count++;
      }
      while (visited.find(pii(r0 + directions[k][0], c0 + directions[k][1])) != visited.end()) {
        r0 += directions[previousK(k)][0];
        c0 += directions[previousK(k)][1];
        if (inside(R, C, r0, c0)) {
          results.push_back(vi {r0, c0});
          count++;
        }
        visited.insert(pii(r0, c0));
      }
      r0 += directions[k][0];
      c0 += directions[k][1];
      k = (k + 1) % 4;
    }
    
    return results;
  }
};
```


## Problem 3
```c++
#define si set<int>
#define mii map<int, int>
#define pii pair<int, int>

class Solution {
private:
  bool pain(mii& color, vector<si>& edges, int index, int c) {
    mii::iterator colorIndex = color.find(index);
    if (colorIndex->second == 0) {
      colorIndex->second = c;
      for (auto e : edges[index]) {
        bool result = pain(color, edges, e, 3 - c);
        if (!result) return false;
      }
    } else {
      if (colorIndex->second != c)
        return false;
      else
        return true;
    }
    return true;
  }
  
public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<si> edges;
    mii color;
    bool result;

    for (int i = 0; i <= N; ++i) {
      edges.push_back(si{}); 
      color.insert(pii(i, 0));
    }
    
    for (auto e : dislikes) {
      edges[e[0]].insert(e[1]);
      edges[e[1]].insert(e[0]);
    }
    for (int i = 1; i <= N; ++i)
      if (color.find(i)->second == 0) {
        result = pain(color, edges, i, 1);
        if (!result) break;
      }
    return result;
  }
};
```


## Problem 4
```c++

```
