## 1. Best Time to Buy and Sell Stock
### 1.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 96ms     | 96.93%      | 93.3 MB  | 33.95%    |

### 1.2. Solution summary

### 1.3. Source code
```cpp
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int minPrice = prices[0], maxProfit = 0;
    for (int i = 1; i < n; i++) {
      minPrice = min(minPrice, prices[i]);
      maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    return maxProfit;
  }
};
```

## 2. Best Time to Buy and Sell Stock with Cooldown
### 2.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 696ms    | 5.30%       | 89.7 MB  | 5.25.44%  |

### 2.2. Solution summary

### 2.3. Source code
```cpp
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();

    if (n < 2) {
      // it is only able to buy not to sell
      // so, not buy anything is the optimal solution
      return 0;
    }

    vector< vector<int> > minPrice(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) {
      minPrice[i][i] = prices[i];
      for (int j = i + 1; j < n; j++) {
        minPrice[i][j] = min(minPrice[i][j - 1], prices[j]);
      }
    }

    vector<int> f(n);
    for (int i = 1; i < n; i++) {
      f[i] = f[i - 1];
      for (int j = i - 1; j >= 0; j--) {
        if (f[j] == 0) {
          f[i] = max(f[i], prices[i] - minPrice[j][i]);
        } else {
          if (j > i - 2) continue;
          f[i] = max(f[i], f[j] + (prices[i] - minPrice[j + 2][i]));
        }
      }
    }

    return f[n - 1];
  }
};
```
