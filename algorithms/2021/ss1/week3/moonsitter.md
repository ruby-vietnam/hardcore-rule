# [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

## Approach

Initial 2 variables:
- `min_price = price_of_the_first_day_in_array`
- `max_profit = 0`

Start from the second day in the array:
- If the price of this day is less than `min_price`, set it to `min_price`.
- If not, it means the price is equal to or larger than `min_price`, so we check whether the profit we get if buying in this day is larger than the current `max_profit` or not. If satisfied, we sell and set this profit to `max_profit`.

**Analysis:**
- Time complexity: `O(n)`
- Space complexity: `O(1)`

**Submission Detail:**
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_profit = 0;
        int n_days = prices.size();
        for (auto i=1; i<n_days; ++i) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            }
            else if ((prices[i] - min_price) > max_profit) {
                max_profit = prices[i] - min_price;
            }
        }
        return max_profit;
    }
};
```
```
Runtime: 96 ms, faster than 96.94% of C++ online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 93.4 MB, less than 34.83% of C++ online submissions for Best Time to Buy and Sell Stock.
```

# [309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

## 0/1 Knapsack Approach
```cpp
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int weight_sum = accumulate(stones.begin(), stones.end(), 0);
        int n_stones = stones.size();
        int max_s2 = weight_sum / 2;
        vector<int> t(max_s2+1, 0);
        for (auto i=0; i<n_stones; i++) {
            vector<int> t_col(t);
            for (auto j=1; j<max_s2+1; j++) {
                if (j < stones[i]) {
                    t[j] = t_col[j];
                }
                else {
                    t[j] = max(t_col[j], t_col[j-stones[i]] + stones[i]);
                }
            }
        }
        return weight_sum - 2*t[max_s2];
    }
};
```
```
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight II.
Memory Usage: 9.1 MB, less than 24.38% of C++ online submissions for Last Stone Weight II.
```
