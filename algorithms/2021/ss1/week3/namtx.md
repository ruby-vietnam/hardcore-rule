# 121. Best Time to Buy and Sell Stock

### Problem

- [Leetcode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

### Approach

To get the maxium profit with just one transaction, we need to by the stock with the lowest price and sell it with the highest price (in a future day)
So, the first thing we need to do is initialize a `minPrice`, and the `maxProfit`

We're gonna loop through the `prices` array. With each price, we compare it with the `minPrice`

- If the price is lower, we need to buy it.
- Otherwise, if the price is greater than the `minPrice` we will consider to sell it by comparing the profit with the `maxProfit` of previous transaction.

### Submission

```java
class Solution {
    public int maxProfit(int[] prices) {
        int minPrice = Integer.MAX_VALUE;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }

        return maxProfit;
    }
}
```

### Submission detail

| Status    | Runtime     | Memory   | Language  |
| ---       | ----------- | -------- | --------- |
| Accepted  | 1ms         | 52.5 MB  | java      |

### Analyze

- Time complexity: **O(n)** as we just loop through the `prices` array one time.
- Space complexity: **O(1)** without extra space needed.

