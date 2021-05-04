# Easy: Best time to buy and sell stock

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

## Submission Details:

```
210 / 210 test cases passed.
Status: Accepted
Runtime: 128 ms
Memory Usage: 8.8 MB
```

## Approach:

We use the first rule of trading: buy low sell high.

For each price in the `prices` array:
- If the current price is lowest, we track it with `buy` variable.
- If sell the stock at current price give us a better profit, track it with the `sell` variable.

Eventually, the `sell` variable is the maximum profit we could take.

## Implementation:

```go
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func maxProfit(prices []int) int {
    n := len(prices)
    buy := -prices[0]
    sell := 0

    for i := 1; i < n; i++ {
        buy = max(buy, -prices[i])
        sell = max(sell, prices[i] + buy)
    }

    return sell
}
```

## Analysis

Since this is a one pass algorithm, the time complexity is `O(n)`.
There are only two variable created (the `buy` and `sell` variables) so the space complexity is `O(1)`.

# Medium: Best time to buy and sell stock with cooldown

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

## Submission Details

```
210 / 210 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.4 MB
```

## Approach

In this problem, we use the `buy[]` array to keep track of the maximum profit from the last buy or cooldown. And
use the `sell[]` array to keep track of the maximum profit from the last sell or cooldown.

For each trading day `i`, we could:

- Calculate the `buy[i]` value by either cooldown or buy at current price:
  + If cooldown, the max profit today is the max profit from buy (or cooldown) from yesterday: `buy[i-1]`.
  + If buy, the max profit would be the max profit from last sell (or cooldown), minus the cost of today stock price: `sell[i-2] - prices[i]` (last sell is `i-2` because `i-1` must be a cooldown)

- Calculate the `sell[i]` value by either cooldown or sell at current price:
  + If cooldown, the max profit today is the max profit from sell (or cooldown) from yesterday: `sell[i-1]`.
  + If sell, the max profit would be the max profit from last buy (or cooldown) plus the stock price today: `buy[i-1] + prices[i]`.

## Implementation

```go
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func maxProfit(prices []int) int {
    n := len(prices)
    if n <= 1 {
        return 0
    }

    buy := make([]int, n)
    sell := make([]int, n)

    buy[0] = -prices[0]

    for i := 1; i < n; i++ {
        last := 0
        if i >= 2 {
            last = sell[i-2]
        }
        buy[i] = max(buy[i-1], last - prices[i])
        sell[i] = max(sell[i-1], buy[i-1] + prices[i])
    }

    return sell[n-1]
}
```

## Analysis

The time complexity is `O(n)` since it's a one pass algorithm.
The space complexity is `O(2n)` (for the two arrays `buy` and `sell`).
