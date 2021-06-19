## 1. Number of Good Pairs
### 1.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 0ms      | 100%        | 7.4 MB   | 14.14%    |

### 1.2. Solution summary
An array with length *N* have *N * (N - 1) / 2* pairs.

If we have an array length *L* in which all elements are equal, the number of good pairs is *L * (L - 1) / 2*.

The idea is accumulate all good pairs of each set of equal numbers.

### 1.3. Source code
```cpp
class Solution {
public:
  int numIdenticalPairs(vector<int>& nums) {
    vector<int> cnt(101);
    for (const int &num : nums) {
      cnt[num]++;
    }

    int64_t ans = 0;
    for (int i = 1; i <= 100; i++) {
      ans += cnt[i] * (cnt[i] - 1) / 2;
    }

    return ans;
  }
};
```

## 2. Partition Array for Maximum Sum
### 2.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 616ms    | 5.20%       | 8.6 MB   | 50.10%    |

### 2.2. Source code
```cpp
class Solution {
public:
  int max_el(vector<int> &arr, const int &i, const int &j) {
    int ans = arr[i];
    for (int idx = i + 1; idx <= j; idx++) {
      ans = max(ans, arr[idx]);
    }
    return ans;
  }

  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    arr.insert(arr.begin(), 0);
    vector<int> dp(n + 1);

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int d = 1; d <= k; d++) {
        if (i - d < 0) break;
        dp[i] = max(
          dp[i],
          dp[i - d] + max_el(arr, i - d + 1, i) * d
        );
      }
    }

    return dp[n];
  }
};
```
