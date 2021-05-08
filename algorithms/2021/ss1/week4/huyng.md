## 1. Determine Color of a Chessboard Square
### 1.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 0ms      | 100%        | 5.9 MB   | 62.38%    |

### 1.2. Solution summary
I translate _[a..z]_ to _[1..27]_. Ok then, if it is odd row,
it should be even column and vice versa to be white cell.

### 1.3. Source code
```cpp
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return ((coordinates[0] - 'a' + 1) & 1)
            + ((coordinates[1] - '0') & 1) == 1;
    }
};
```

## 2. Determine Color of a Chessboard Square
### 2.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 208ms    | 30.04%      | 44 MB    | 23.82%    |

### 2.2. Solution summary

### 2.3. Source code
```cpp
const int MOD = 1000000007;

class Solution {
public:
  int knightDialer(int n) {
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> adj = {
      {4, 6},
      {6, 8},
      {7, 9},
      {4, 8},
      {3, 9, 0},
      {},
      {1, 7, 0},
      {6, 2},
      {1, 3},
      {2, 4}
    };

    using MemoType = int64_t;
    vector<MemoType> f(10, 1);
    for (int i = 2; i <= n; i++) {
      vector<MemoType> f_next(f.size());
      for (int u : nums) {
        for (int v : adj[u]) {
          f_next[u] = (f_next[u] + f[v]) % MOD;
        }
      }
      f = f_next;
    }

    MemoType res = 0LL;
    for (int u : nums) {
      res = (res + f[u]) % MOD;
    }

    return res;
  }
};
```