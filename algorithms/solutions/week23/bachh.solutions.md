
# Problem 2
```cpp
#include <string>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
  public:
    string simplifyPath(string path){
      vector<string> st = vector<string>(100000);
      string ret = "/";
      int top = 0;
      int i;
      for(i=0; i < path.length(); i++){
        if(path[i] == '/'){
          int j = i+1;
          while(j < path.length() && path[j] != '/'){
            j++;
          }
          string str = path.substr(i+1, j-i-1);
          if(str == "..") {
            top = max(0, top-1);
          }
          else if (str != "." && j > i+1) {
            st[top++] = str;
          }
        }
      }
      for(i = 0; i < top; i++){
        ret += st[i];
        if (i<top-1) ret += "/";
      }
      return ret;
    }
  };
```

# Problem 3

```cpp
#include <bits/stdc++.h>
#include <algorithm>

typedef long long ll;
using namespace std;

class Solution{
public:
  > double new21GameDP(int N, int K, int W) {
  >   int len = max(N,K ) + 1;
  >   double *memoi = (double*) malloc(len*sizeof(double));
  >   fill(memoi, memoi+len, -10.0);
  >   return recurse(memoi, N, K, W);
  > }
  > double recurse(double* memoi, int N, int K, int W){
  >   double ret = 0;
  >   if (K <= 0 && N >= 0) return 1;
  >   if (N < 0) return 0;
  >   if(memoi[N] > 0) return memoi[N];
  >   for(int i = 1; i <= min(W, N); ++i){
  >     ret += ( double(1)/W )*(recurse(memoi, N-i, K-i, W));
  >   }
  >   return memoi[N] = ret;
  > }

  double new21Game(int N, int K, int W){
    int base = N-K+1;
    int k = 1;
    double accum = 1;
    double result = 1;
    while(base <= N){
      double ret = accum/double(W);
      /* for (int i = 1; i <= min(k, W); ++i) { */
      /*   ret += memoi[base - i]/double(W); */
      /* } */
      double over = max(0, min(base-k, W-k))/double(W);
      result = accum/double(W) +over;
      accum += result;
      base++;
      k++;
    }
    return result;
  }
};
```


