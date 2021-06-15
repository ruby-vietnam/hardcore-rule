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
