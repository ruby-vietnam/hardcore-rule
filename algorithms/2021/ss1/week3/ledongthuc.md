# 1. Best Time to Buy and Sell Stock

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

## 1.1. Summary

We need to find the maximum profit between buying and selling on a range of dates.
Or technically, we compare any profit if we buy in a date and sell it later.
The final comparison will be the best profit we can have in range date.
We got the idea, but we have two approaches to solve this issue:
 - From chart view
 - From table accounting view

## 1.2. Chart view

So take a look at the chart, it's familiar if we have experience in investment.

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/best-time-to-buy-and-sell-stock/BestTimeToBuyAndSellStock-Chart.png)

From the chart, we have 2 things here:
 - Date from t(0) to t(n)
 - Stock values v(0) to v(n)

Classical, to calculate the profit, every investor will go date by date, from t(0) => t(n)
 - If we buy a stock on `t-1`, but on `t` the price's down. It means we don't have any profit
 - If we buy a stock on `t-1`, and on `t` the price's up, it means we have a profit

To keep the maximum stock profit, we need to buy at stock value is min and sell it at top stock value.

the solution here is we go through t(0) to t(n), cache the max profit and last min stock value
 - If stock on `t` is less than the last Min Stock Value, it means v(t) will be the last Min Stock Value. In this case, the stock's price is down and of course, we don't have any profit. We update the Min Stock Value to v(t) means we understand we should buy it at v(t), when it's cheaper.
 - If the stock value on `t` is greater than Min Stock Value, we will calculate profit from `v(t) - Last Min Stock Value`. We compare it with Max profit. If it's greater than, it mean we're better profit if we sell it on `v(t)`, but it's less than, we ignore it, and we shouldn't sell it on `t` if we want maximum final profit.
 - Finally, after finish (n) dates, we will know what's maximum profit if we buy/sell at the best timing from the cache of Max Profit.

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/best-time-to-buy-and-sell-stock/BestTimeToBuyAndSellStock-Chart-line.png)

```go
func maxProfit(prices []int) int {
	minPrice := int(math.MaxInt32)
	maxProfit := 0
	for _, value := range prices {
		if minPrice > value {
			minPrice = value
		} else {
			profit := value - minPrice
			if profit > maxProfit {
				maxProfit = profit
			}
		}
	}
	return maxProfit
}
```

## 1.3. Table accounting view

Forget about charts and investment view. Let's take a look at the accounting view:
 - We find Maximum Profit every day (even sell or not sell anything)
 - To find Maximum Profit every day, we need to know what's last minimum stock value when we bought it before.

### 1.3.1. Last minimum stock value of everyday

Every day, we need to know what is last minimum stock before when we buy the stock. Base on it, we can calculate daily profit.

To calculate it, we compare the minimum stock value of yesterday with today stock value. The smaller value will be the minimum stock value today.

```
minValue(t) = getMin( minValue(t-1) , value(t) )
```

### 1.3.2. Maximum Profit everyday

Every day, the maximum profit is a comparison between the last Maximum Profit with the profit if today we sell the stock with the last minimum stock value.

```
MaxProfit(t) = getMax( MaxProfit(t-1), value(t) - minValue(t-1) )
```

So if we have range n dates, the MaxProfit at date (n) will be the MaxProfit if we buy/sell stock at the best timing during n dates.

### 1.3.4. Code

```go
func maxProfit(prices []int) int {
    minAtTime := make([]int, len(prices), len(prices))
    maxProfitAtTime := make([]int, len(prices), len(prices))
    
    for i, price := range prices {
        if i == 0 {
            minAtTime[i] = price
            maxProfitAtTime[i] = 0 
            continue
        }
        minAtTime[i] = min(minAtTime[i-1], price)
        maxProfitAtTime[i] = max(maxProfitAtTime[i-1], price - minAtTime[i])
    }
    
    return maxProfitAtTime[len(prices) - 1]
}

func min(i, j int) int {
    if i < j {
        return i
    }
    return j
}

func max(i, j int) int {
    if i > j {
        return i
    }
    return j
}
```

# 2. Best Time to Buy and Sell Stock

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

## 2.1. Summary

The solution of this problem is inherit from https://github.com/ledongthuc/notes/tree/master/leetcode/best-time-to-buy-and-sell-stock
It means we will go through date by date, find the maximum profit we can have in this date.
But first, let's check cases that we have on random date:

**Case 1: Starting point**

Nothing special here.
As we can see, we can't buy and sell to any profit from same date.
So t(n) with n = 0 always has profit is 0.

```
profit(0) = 0
```

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/best-time-to-buy-and-sell-stock-with-cooldown/BestTimeToBuyAndSellStockWithCooldown-Chart-0.png)

**Case 2: Cooldown date**

If a date is cooldown date, it means we can't buy anything, and of couse we can't sell anything too (because have just sell yesterday).

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/best-time-to-buy-and-sell-stock-with-cooldown/BestTimeToBuyAndSellStockWithCooldown-Chart-cooldown.png)
This case occurs if price on (t) is less than price of (t-1). So we don't have any reason to keep to (t), just sell it on (t-1) to have higher profit. Then, profit on cooldown date (t) is always same max profit we have on (t-1).

```
profit(t) = maxProfit(t-1)
```

**Case 3: Selling date without spliting**

If we decide to sell on date (t), the profit will be the gain from buying price to price today (t)
The buying price is the minimum price from beginning to (t).

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/best-time-to-buy-and-sell-stock-with-cooldown/BestTimeToBuyAndSellStockWithCooldown-Chart-sell.png)
```
profit(t) = price(t) - min
| with min = min( prices in range 0 -> (t-1))
```

**Case 4: Selling date with spliting**

Let's check an special case that we buy-sell many times, we will have cooldown date between buy-sell cycle

![enter image description here](https://raw.githubusercontent.com/ledongthuc/notes/master/leetcode/best-time-to-buy-and-sell-stock-with-cooldown/BestTimeToBuyAndSellStockWithCooldown-Chart-sell-with-cooldown.png)

So with this special case, If we split it to 2 times of buy-sell, the profit of date (t) can be bigger than just buy on t1 and sell on t5.

The question is when is best cooldown date should be. To answer this question, we go through x in range from 2 to t-1, calculate all profit if x-1 is a cooldown date to get best profit at best cooldown date.

> Why start from 2. Because in order to have cooldown date, at least, we need to buy from t(0) and sell on t(1)

Then profit in special case will be:

```
profit(t) = price(t) - price(x) + MaxProtfit(x-2)
| with x = range 2 -> t-1
```

## 2.2. Solution

To solve the full problem, we calculate the maximum profit of latest date.

To calculate maximum profit of latest date, we calculate maximum profit of previous dates.

As 3 cases we checked above, to calculate maximum profit of a date (t), it's a decision making to get best profit between:
 - Don't do anything on (t). Sell stock on (t-1) and keep (t) as cooldown date. Max profit (t) will be max profit that's sold on (t-1)
 - Sell stock on (t), with buying date is min date from beginning to (t-1)
 - Sell stock on (t), with buying date is any date from 2 to (t-1) after cooldown date to give best profit.

```
MaxProfit(t) = getMax( MaxProfit(t-1), getMax(price(t) - min, price(t) - price(x) + MaxProtfit(x-2)))
| with x = range 2 -> t-1
| with min = min( prices in range 0 -> (t-1))
```



**1. Optimize to find min**

With any date (t), we can caculate the minimum price from 0 to (t)

```
for i in range 0 -> t:
   minPrice = getMin(i, price[t])
```

If we break it to smaller problem, it will be

```
minPrice[0] = prices[0]
minPrice[1] = getMin(prices[1], minPrice[1 - 1])
minPrice[2] = getMin(prices[2], minPrice[2 - 1])
minPrice[3] = getMin(prices[3], minPrice[3 - 1])
...
minPrice[t] = getMin(price[t], minPrice[t-1])
```
So, we can cache it everyday to reuse.

**2. Optimize to find x**

With each date (t), we need have a nested loop from 2 to (t-1) to find x

```
Profit(t) if cooldown on (x-1) = price(t) - price(x) + MaxProtfit(x-2)
<=>
Profit(t) if cooldown on (x-1) = price(t) - ( price(x) - MaxProtfit(x-2) )
```

In order to keep `Profit(t) if coolddown on (x-1)` is maximum value, with `price(t)` is fixed,
then `price(x) - MaxProtfit(x-2)` must be minimum value.
So now we have another problem need to solve, how to find minimum of `price(x) - MaxProtfit(x-2)`,
or we can understand, how to find minimum value of `minX(x) = price(x) - MaxProtfit(x-2)` should be to buy with 

```
minX(0) = prices(0)
minX(1) = getMin( prices(1), prices(0) )
minX(2) = getMin( C(2-1), price(2) - MaxProtfit(2-2) )
minX(3) = getMin( C(3-1), price(3) - MaxProtfit(3-2) )
minX(4) = getMin( C(4-1), price(4) - MaxProtfit(4-2) )
...
minX(t) = getMin( C(t-1), price(t) - MaxProfit(t-2) )
```

So, we can calculate and cache the `minX(t)` by pickup minimum value of:
 - price(t) - MaxProtfit(t-2): in this case, we buy on (t), cooldown on (t-1), sell on (t-2). So the price gap here is new on (t) and last selling(t-2).
 - minX(t-1): check previous date if cooldown on ((t-1)-1). If it has smaller price to buy, then it's worth to buy instead.

Now, we can cache the `minX` everyday to reuse.
To calculate MaxProfit(t) if has cooldown, it's gain from minimum price date from `minX` of (t-1) to price(t)

```
MaxProfit(t) if cooldown = price(t) - minX(t-1)
<=>
MaxProfit(t) if cooldown = price(t) - getMin( minX(t-2), price(t-1) - MaxProtfit(t-3) )
```

**Solution after optimization**

After apply optimization, it should be:

```
MaxProfit(t) = getMax(
	MaxProfit(t-1),                                                  # t = cooldown
	price(t) - minPrice(t-1),                                        # sell t, buy from min in range 0 -> t-1
	price(t) - getMin( minX(t-2), price(t-1) - MaxProtfit(t-3) ),    # sell t, buy from the date next to cooldown with best profit
)
```

```go
func maxProfit(prices []int) int {
    if len(prices) <= 1 {
        return 0
    }
    if len(prices) == 2 {
        return max(0, prices[1] - prices[0])
    }

    minPrices := make([]int, len(prices), len(prices))
    minPrices[0] = prices[0]
    minPrices[1] = min(prices[0], prices[1])
    minX := make([]int, len(prices), len(prices))
    minX[0] = prices[0]
    minX[1] = prices[1]
    maxProfit := make([]int, len(prices), len(prices))
    maxProfit[0] = 0
    maxProfit[1] = max(0, prices[1] - prices[0])

    for i := 2; i < len(prices); i++ {
        minPrices[i] = min(prices[i], minPrices[i-1])
        minX[i] = min( minX[i-1], prices[i] - maxProfit[i-2])
        maxProfit[i] = max(
            maxProfit[i-1], 
            prices[i] - minX[i-1],
            prices[i] - minPrices[i-1],
        )
    }

    return maxProfit[len(prices) - 1]
}

func min(i, j int) int {
    if i < j {
        return i
    }
    return j
}

func max(numbers ...int) int {
    if len(numbers) == 0 {
        return 0
    }

    max := numbers[0]
    for _, n := range numbers {
        if n > max {
            max = n
        }
    }
    return max
}
```
