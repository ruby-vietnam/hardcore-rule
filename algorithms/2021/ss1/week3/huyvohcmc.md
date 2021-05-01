# Easy: Best Time to Buy and Sell Stock

Leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

### Approach

This is similar to finding min & max number in an array, but this time we're finding min price and maximum profit. Maximum profit can be understand as `max price - min price`, but this max price must appear after min price in the prices array. We can use 1 variable to keep the min price at ith iteration of the loop, and 1 variable to keep the max profit at ith iteration (`prices[i] - minPrice`).

### Code (Go)

```go
func maxProfit(prices []int) int {
	minPrice, maxProfit := prices[0], 0

	for _, price := range prices {
		if price < minPrice {
			minPrice = price
		} else if price-minPrice > maxProfit {
			maxProfit = price - minPrice
		}
	}

	return maxProfit
}
```

Time complexity: O(n), space complexity: O(2).

### Submission Detail

```
210 / 210 test cases passed.
Status: Accepted
Runtime: 132 ms
Memory Usage: 8.8 MB
```

# Medium: Best Time to Buy and Sell Stock with Cooldown

Leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

### Approach

We will use dynamic programming to solve this problem. For any day there are 2 possibilities:
- we have a stock on that day (1)
- we don't have any stock on that day (2)

To build up the solution, we will use a 2-dimensional array `dp[n][2]` for 2 possibilities: `dp[i][0]` is the maximum profit when we don't have any stock left at the end of day `i`, and `dp[i][1]` is the maximum profit when we have a stock left at the end of day `i`.

(1) has 2 possibilities:
- we bought the stock today (A)
- we bought the stock in the past, doing nothing today (B)

(2) has 2 possibilities:
- we sold the stock today (A)
- we sold the stock in the past, doing nothing today (B)

Let's go through each case in more details:

#### (1A)

We bought the stock today, which means yesterday was the cooldown day, so our max profit = (max profit on day i-2) - today's stock price.
- `dp[i-2][0] - prices[i]`

Why `dp[i-2][0]`? Because at the end of day `i-2`, we must have sold the stock so we can buy it again on day `i`.

#### (1B)

We bought the stock in the past: max profit = max profit of yesterday when we have a stock left.
- `dp[i-1][1]`

#### (2A)

We sold the stock today, which means max profit = max profit of yesterday, when we have a stock left, plus today's stock price.
- `dp[i-1][1] + prices[i]`

#### (2B)

We sold the stock in the past, so our max profit will be just the same as the day before.
- `dp[i-1][0]`

When case (1) happens on day i, our max profit is whichever is larger between (1A) and (1B). Similarly, when case (2) happens on day i, max profit is max(2A, 2B). In the end, we return the max profit of the last day without any stock, because we don't want to hold a stock as there's no other day to sell it.


### Code (Go)

```go
func maxProfit(prices []int) int {
	n := len(prices)
	if n == 1 {
		return 0
	}

	if n == 2 && prices[0] < prices[1] {
		return prices[1] - prices[0]
	} else if n == 2 && prices[0] > prices[1] {
		return 0
	}

	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, 2)
	}

	dp[0][0] = 0
	dp[0][1] = -prices[0]
	dp[1][0] = max(dp[0][0], dp[0][1]+prices[1])
	dp[1][1] = max(dp[0][1], dp[0][0]-prices[1])

	for i := 2; i < n; i++ {
		dp[i][0] = max(dp[i-1][1]+prices[i], dp[i-1][0])
		dp[i][1] = max(dp[i-2][0]-prices[i], dp[i-1][1])
	}

	return dp[n-1][0]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```

Time complexity: O(n), space complexity: O(2n).

### Submission Detail

```
210 / 210 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.6 MB
```
