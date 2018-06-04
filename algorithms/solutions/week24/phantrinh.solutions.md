### Prolem 1 - [Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/description/)

Status:
```
  ✔ Accepted
  ✔ 124 / 124 test cases passed (5 ms)
```

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 2; i * i <= c; ++i) {
            int cnt = 0;
            while (c % i == 0) {
                c /= i;
                ++cnt;
            }
            if (i % 4 == 3 && (cnt & 1)) return 0;
        }
        if (c > 1 && c % 4 == 3) return 0;
        return 1;
    }
};
```

### Prolem 2 - [Largest Number](https://leetcode.com/problems/largest-number/description/)

Status:
```
  ✔ Accepted
  ✔ 222 / 222 test cases passed (18 ms)
```

```cpp
class Solution {
    static bool cmp(int a, int b) {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ret = "";
        for (int i = 0; i < nums.size(); ++i) {
            ret += to_string(nums[i]);
        }
        int i = 0;
        while (i + 1 < ret.size() && ret[i] == '0') ++i;
        return ret.substr(i);
    }
};
```

### Problem 3 - [Coin Change](https://leetcode.com/problems/coin-change/description/)

Status:
```
  ✔ Accepted
  ✔ 182 / 182 test cases passed (38 ms)
```

Code:
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int *f = new int[amount + 1];
        for (int i = 0; i <= amount; ++i) f[i] = -1;
        f[0] = 0;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = 0; j + coins[i] <= amount; ++j) {
                if (f[j] != -1) {
                    if (f[j + coins[i]] == -1)
                        f[j + coins[i]] = f[j] + 1;
                    else
                        f[j + coins[i]] = min(f[j + coins[i]], f[j] + 1);
                }
            }
        }
        int t = f[amount];
        delete[] f;
        return t;
    }
};
```

### Problem 4 - [Split Array With Same Average](https://leetcode.com/problems/split-array-with-same-average/description/)

Status:
```
  ✔ Accepted
  ✔ 88 / 88 test cases passed (168 ms)
```

Code:
```cpp
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        bitset<300006> f[16];
        int s = 0;
        f[0][0] = 1;
        for (int i = 0; i < A.size(); ++i) {
            s += A[i];
            for (int j = s; j - A[i] >= 0; --j) {
                for (int k = 1; k <= A.size() / 2; ++k) {
                    if (f[k - 1][j - A[i]]) {
                        f[k][j] = 1;
                    }
                    
                }
            }
        }
        for (int i = 1; i + i <= A.size(); ++i) {
            if (s * i % A.size() != 0) continue;
            if (f[i][s * i / A.size()]) {
                return 1;
            }
        }
        return 0;
    }
};
```