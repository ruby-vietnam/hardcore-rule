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

Consider for `maxProfit[i]`, what kind of `i` is
We have 3 options: `buy day, cooldown day, sell day`.

- It cannot be a `buy day`, since we cannot make any profit buying at the last day because you have no chance to sell it. So 2 possibilities left: `cooldown day`, `sell day`.
- If It is a `cooldown day`, then the max profit is the same as day `i - 1 => maxProfit[i] = maxProfit[i - 1]` (1)
- If it is a `sell day`, then which day is the `buy day`? The buy day could be any days before day `i`(exclusive, i.e. `0 to i - 1`). Let's denote it as `j`, then the profit we get `= nums[i] - nums[j] + previous day's profit`. The problem becomes what is the previous days' profit? To figure it out, ask youself what about the day `j - 1`?
  - `j - 1` cannot be a `buy day`. Since you cannot have 2 continuous days(`j - 1` and `j`) as the `buy day`, you must sell the stock before you buy again as required.
  - `j - 1` cannot be a `sell day` as well, because if it is, day `j` must be a `cooldown day`.
  - Thus, day `j - 1` must be a `cooldown day`. If it is a `cooldown day`, then the max profit we can get at day `j - 1` is `maxProfit[j - 2]`
  - So, `maxProfit[i] = max(maxProfit[j - 2] + nums[i] - nums[j]) for j = 0 to i - 1` (2)

From (1) and (2), we know that:
`maxProfit[i] = max(maxProfit[i - 1], max(maxProfit[j - 2] + nums[i] - nums[j]) for j = 0 to i - 1)` (3)

```swift
class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        guard prices.count > 0 else { return 0 }
        let n = prices.count

        var maxProfit = Array(repeating: 0, count: n)
        for i in 0 ..< n {
            if i == 0 {
                maxProfit[0] = 0
            } else if i == 1 {
                maxProfit[1] = max(prices[1] - prices[0], 0)
            } else {
                maxProfit[i] = maxProfit[i - 1]
                for j in 0 ..< i {
                    let prev = j >= 2 ? maxProfit[j - 2] : 0
                    maxProfit[i] = max(maxProfit[i], prev + prices[i] - prices[j])
                }
            }
        }
        return maxProfit[n - 1]
    }
}
```
```
Runtime: 264 ms, faster than 10.00% of Swift online submissions for Best Time to Buy and Sell Stock with Cooldown.
Memory Usage: 14.1 MB, less than 60.00% of Swift online submissions for Best Time to Buy and Sell Stock with Cooldown.
```

with this approach the
- Time would be `O(N ^ 2)`
- Space would be `O(N)`

but if you notice from (3), `maxProfit[j - 2] + nums[i] - nums[j]` can be transformed to `(maxProfit[j - 2] - nums[j]) + nums[i]`, and `maxProfit[j - 2] - nums[j]` is the only variable changing. Then if we keep a variable(`maxDiff`) to keep track of the max of it, so (3) can be changed to `maxProfit[i] = max(maxProfit[i - 1], maxDiff + nums[i]) for j = 0 to i - 1)`

from this approach time complexity will be optimized to `O(N)`

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