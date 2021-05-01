# Best Time to Buy and Sell Stock [Easy]

Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

## 1. Idea

That was easy to think. I dont understand how and why people keep using dynamic
programming for this problem. Or maybe I just dont understand dp well, sadly...

So I try my best. that is traverse. Just go straight input array to find
smallest and largest number. The subtract of them is the result.

![Explain](https://raw.githubusercontent.com/monodyle/algorithms-adventure/master/leetcode-problems/121-best-time-to-buy-and-sell-stock/best-time-to-buy-and-sell-stock.png)

## 2. Example

```go
func maxProfit(prices []int) int {
	l, h := prices[0], 0
	for _, p := range prices {
		l = min(p, l)
		h = max(h, p-l)
	}
	return h
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
```

## 3. Submission Detail

```
210 / 210 test cases passed.
Status: Accepted
Runtime: 120 ms
Memory Usage: 8.7 MB
```

# Best Time to Buy and Sell Stock with Cooldown [Medium]

Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

## 1. Idea

So the problem have 2 rules:

1. Have to `rest` before `buy`
2. Have to `buy` before `sell`

We can have all actions:

- After Rest `r` => Rest | Buy
- After Buy `b` => Rest | Sell
- After Sell `s` => Rest

As you see there are three states, according to the action that you can do.
From this, you can know the profit at (`t`) time as:

```
buy[t] = max(rest[t-1] - price, buy[t-1])
sell[t] = max(buy[t-1] + price, sell[t-1])
rest[t] = max(sell[t-1], buy[t-1], rest[t-1])
```

Where:

- `t`: the day from 0 (start) to checking time
- `price`: price of day `t`

Fact: `buy[t] <= rest[t]` so that mean `rest[t] = max(sell[t-1], rest[t-1])`.
That make sure `buy` -> `rest` -> `buy` is never occured.

As observation, `rest[t] <= sell[t]` is also true. Therefore:
`rest[t] = sell[t-1]`

## 2. Example

```go
func maxProfit(prices []int) int {
	if len(prices) < 2 {
		return 0
	}
	r, h, s := 0, -prices[0], 0
	for i := 1; i < len(prices); i++ {
		_s := s
		s = h + prices[i]
		h = max(r-prices[i], h)
		r = max(r, _s)
	}
	return max(r, s)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```

## 3. Submission Detail

```
210 / 210 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.3 MB
```
