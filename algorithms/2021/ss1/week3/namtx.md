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

#  309. Best Time to Buy and Sell Stock with Cooldown

### Approach

As we can see, on each single day, we have four states as following:
- `S1`: you have 1 stock, and you decide to sell it.
- `S2`: you have 1 stock and do nothing
- `S3`: you have 0 stock and decide to buy 1
- `S4`: you have 0 stock and do nothing

For each state at day `i`, we have to took and action at day `i-1`

- At day `i`, if we have state `S1` we should had 1 stock and do nothing or had 0 stock and bought 1 stock (`S2` or `S3`) at day `i-1`
- At day `i`, if we have state `S2` we should had 1 stock before and didn't nothing or bought 1 stock (`S2` or `S3`) at day `i-1`
- At day `i`, if we have state `S3` we should 0 stock and didn't nothing (you couldn't sell with `S1` as cooldown) at day `i-1`
- At day `i`, if we have state `S4` we should 1 stock and sold it, or you had 0 stock and didn't nothing (`S1` or `S4`)

After interactively went though all days, we can easily get the maxium between `S1` and `S4`

We have a special case as if we start at day `0` and state `S2` (you don't have any stock and hold it???) so we will initialize the `S2` with `-prices[0]` to make the profit is correct.

### Submission

```java
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if (n < 2) return 0;

        /*
        Four states:
        - s1: has 1 stock and sell it
        - s2: has 1 stock and do nothing
        - s3: has 0 stock and buy stock
        - s4: has 0 stock and do nothing
         */

        int s1 = 0;
        int s2 = -prices[0];
        int s3 = -prices[0];
        int s4 = 0;

        for (int i = 1; i < n; i++) {
            s2 = Math.max(s2, s3);
            s3 = -prices[i] + s4;
            s4 = Math.max(s4, s1);
            s1 = prices[i] + s2;
        }

        return Math.max(s1, s4);
    }
}
```

### Submission detail

| Status    | Runtime     | Memory   | Language  |
| ---       | ----------- | -------- | --------- |
| Accepted  | 1ms         | 36.7 MB  | java      |

### Analyze

- Time complexity **O(n)**
- Space complexity **O(1)**
