# 1. Easy:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

## 1.1: Naive Solution:
We run two loops save all profit we can get into an array. After that we will find max value. this approach ahve complexcity is O(n^2)

Submission Details
```
198 / 210 test cases passed.
Status: Time Limit Exceeded
```

Implementation:
```go
func maxProfit(prices []int) int {
	n := len(prices)
	if n == 1 {
		return 0
	}
	res := make([]int, 0)

	for i:= 0; i < n - 1; i++ {
		for j:= i + 1; j < n; j++ {
			res = append(res, prices[j] - prices[i])
		}
	}
	sort.Slice(res, func(i, j int) bool {
		return  res[i] > res[j]
	})
	max := res[0]
	if max < 0 { return 0 }
	return max
}
```

 # 1.2: Better Solution:
Run one loop and we will find maxprofit with minprice on the right of array prices
This approach wil have complexity O(n)

Submission Details
```
210 / 210 test cases passed.
Status: Accepted
Runtime: 132 ms
Memory Usage: 8.9 MB
```


Implementation:
```go
func maxProfit(prices []int) int {
	minPrice := prices[0]
	maxProfit := 0

	for i := 0; i < len(prices); i++ {
		if prices[i] - minPrice > maxProfit {
			maxProfit = prices[i] - minPrice
		}
		if minPrice > prices[i] {
			minPrice = prices[i]
		}
	}

	return maxProfit
}
```

# 2: Medium: best-time-to-buy-and-sell-stock-with-cooldown
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/


Submission Details
```
210 / 210 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.4 MB
```

Implementation:
```go
func maxProfit(prices []int) int {
	buy := make([]int, len(prices))
	sell := make([]int, len(prices))
	rest := make([]int, len(prices))
	buy[0] = -prices[0]
	sell[0] = math.MinInt8
	rest[0] = 0
	for i := 1; i < len(prices); i++ {
		rest[i] = max(rest[i - 1], sell[i - 1])
		buy[i] = max(buy[i - 1], rest[i - 1] - prices[i])
		sell[i] = buy[i - 1] + prices[i]
	}

	return max(rest[len(prices) - 1], sell[len(prices) -1])
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return  b
}
```

