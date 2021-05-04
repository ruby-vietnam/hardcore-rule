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

## 3. Best Time to Buy and Sell Stock IV
### 3.1. Summary
| Runtime  | Faster than | Memory   | Less than |
| :----:   | :----:      | :----:   | :----:    |
| 1540ms   | ?%          | 23.5 MB  | ?%        |

### 3.2. Solution summary

### 3.3. Source code
```cpp
class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    int n = prices.size(), maxBuy = k;

    if (maxBuy == 0 || n == 0) {
      return 0;
    }

    vector< vector<int> > maxProfit(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      int minCost = prices[i];
      for (int j = i; j < n; j++) {
        minCost = min(minCost, prices[j]);
        maxProfit[i][j] = prices[j] - minCost;
      }
    }

    vector< vector<int> > f(n, vector<int>(maxBuy + 1, 0));
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        //f[i][0] = *max_element(f[i-1].begin(), f[i-1].end());
        for (int cnt = 0; cnt <= maxBuy; cnt++) {
          f[i][cnt] = f[i-1][cnt];
        }
      }
      f[i][1] = max(f[i][1], maxProfit[0][i]);
      for (int cnt = 1; cnt <= maxBuy; cnt++) {
        for (int j = i - 1; j >= 0; j--) {
          f[i][cnt] = max(f[i][cnt], f[j][cnt-1] + maxProfit[j+1][i]);
        }
      }
    }

    return *max_element(f[n-1].begin(), f[n-1].end());
  }
};
```
