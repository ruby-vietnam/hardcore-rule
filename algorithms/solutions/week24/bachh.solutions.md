# Problem 1

```cpp
#include <bits/stdc++.h>
#include <algorithm>

typedef long long ll;
using namespace std;

#define MONAD 1e-6

class Solution {
public:
    bool judgeSquareSum(int c) {
      int a = 0;
      for(int i = 0; i <= sqrt(c); ++i){
        a = c - i*i;
        if (a - floor(sqrt(a)) *floor(sqrt(a)) == 0 ){
          return true;
        }
      }
      return false;
    }
};

```

# Problem 3

```cpp
#include <bits/stdc++.h>
#include <algorithm>

typedef long long ll;
using namespace std;
#define INF 1e9



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int memoi[1000000];
      memset(memoi, -1, sizeof(int)*1000000);
      recurse(memoi, coins,  amount);
      if (memoi[amount] < INF) return memoi[amount];
      return -1;
    }


    int recurse(int* memoi, vector<int>& coins, int amount){

      if(amount == 0) return memoi[amount] = 0;
      if(amount < 0) return INF;
      if(memoi[amount] > -1) return memoi[amount];
      int mi = INF;

      for(int coin : coins){
        mi = min(recurse(memoi, coins, amount - coin), mi);
      }

      return memoi[amount] = mi+1;
    }

};
```
