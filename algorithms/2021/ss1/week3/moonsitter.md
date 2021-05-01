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

**Submission Detail:**
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int rest = 0;
        int buy = -prices[0];
        int sell = 0;
        for (auto i=1; i<n; ++i) {
            auto prev_buy = buy;
            auto prev_sell = sell;
            buy = max(rest - prices[i], buy);
            sell = max(prev_buy + prices[i], sell);
            rest = max(max(prev_sell, prev_buy), rest);
        }
        return max(sell, rest);
    }
};
```
```
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
Memory Usage: 11.2 MB, less than 71.78% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
```
