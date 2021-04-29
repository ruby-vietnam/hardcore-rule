# 1. Best time to Buy and Sell Stock

- `minPrice` is the minimum price from day 0 to day `i`. `maxProfit` is the maximum profit we can get from day 0 to day `i`.
- To get the `maxProfit`, just get the larger one between current `maxProfit` and `price - minPrice`

```swift
class Solution {
  func maxProfit(_ prices: [Int]) -> Int {
    var maxProfit = 0
    var minPrice = Int.max
    for price in prices {
      minPrice = min(price, minPrice)
      let profit = price - minPrice
      maxProfit = max(profit, maxProfit)
    }
    return maxProfit
  }
}
```
```
Runtime: 992 ms, faster than 27.94% of Swift online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 17.7 MB, less than 54.29% of Swift online submissions for Best Time to Buy and Sell Stock.
```

# 2. Best Time to Buy and Sell Stock with Cooldown

```swift
class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        guard prices.count > 0 else { return 0 }
        let n = prices.count

        var maxProfit = Array(repeating: 0, count: n)
        var maxDiff = Int.min

        for i in 0 ..< n {
            if i < 2 {
                maxDiff = max(maxDiff, -prices[i])
            }

            if i == 0 {
                maxProfit[0] = 0
            } else if i == 1 {
                maxProfit[1] = max(prices[1] - prices[0], 0)
            } else {
                maxProfit[i] = max(maxProfit[i - 1], maxDiff + prices[i])
                maxDiff = max(maxDiff, maxProfit[i - 2] - prices[i])
            }
        }

        return maxProfit[n - 1]
    }
}
```
```
Runtime: 8 ms, faster than 95.65% of Swift online submissions for Best Time to Buy and Sell Stock with Cooldown.
Memory Usage: 13.9 MB, less than 95.65% of Swift online submissions for Best Time to Buy and Sell Stock with Cooldown.
```