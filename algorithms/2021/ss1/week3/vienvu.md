#Easy: best-time-to-buy-and-sell-stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock

Naive Solution:
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

Better Solution:
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

#Medium: best-time-to-buy-and-sell-stock-with-cooldown
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/



