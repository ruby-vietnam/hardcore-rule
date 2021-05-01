## 121. Best Time to Buy and Sell Stock

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Iterate each price in the list, the maximum profit is the difference between the current price and the previous minimum price. The naive implementation is to loop back and find the minimum price. However, this problem can be optimize by maintaining a variable, and update accordingly when iterating to the new one.

```ruby
def max_profit(prices)
  min = prices[0]
  max = 0

  1.upto(prices.length - 1) do |i|
    min = prices[i] if min > prices[i]
    max = prices[i] - min if prices[i] - min > max
  end

  max
end
```

```
Runtime: 288 ms, faster than 5.26% of Ruby online submissions for Best Time to Buy and Sell Stock.
Memory Usage: 219.5 MB, less than 62.03% of Ruby online submissions for Best Time to Buy and Sell Stock.
```

## 309. Best Time to Buy and Sell Stock with Cooldown

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

Let t (i, a) is the maximum profit when iterating to day i and perform action a ('sell' is 1 and 'cooldown' is 0).
- t[i][0] = max(t[i][0], t[i][1]). It means that if we don't perform any action on day i, the maximum profit should be the previous cooldown day or previous selling day.
- t[i][1] = max(prices[i] - prices[j] + t[j-1][0]). Going back to compare the price and calculate the profit. The profit is calculated by getting the price difference between i and j plus the profit if day j - 1 is cooldown.

```ruby
def max_profit(prices)
    t = Array.new(prices.length) { [0, 0] }
    min = 0
    max = 0

    1.upto(prices.length - 1) do |i|
        min = i if prices[i] < prices[min]

        t[i][0] = [t[i - 1][0], t[i -1][1]].max
        i.downto(min) do |j|
            next if prices[j] >= prices[i]

            previous = j > 0 ? t[j-1][0] : 0
            profit = prices[i] - prices[j] + previous
            t[i][1] = profit if profit > t[i][1]
            max = profit if max < profit
        end
    end
    max
 end
```

```
Runtime: 400 ms, faster than 6.79% of Ruby online submissions for Best Time to Buy and Sell Stock with Cooldown.
Memory Usage: 219.5 MB, less than 62.03% of Ruby online submissions for Best Time to Buy and Sell Stock with Cooldown.
```
