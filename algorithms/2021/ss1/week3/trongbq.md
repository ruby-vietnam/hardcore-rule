# Week 3

## Problem 1
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

### Brute Force
Iterate through all pairs of buying and selling days, we record the maximum profit we can get from these pairs.

**Analysis**

Total number of pairs is nC2 = n*(n-1), so time complexity is O(n^2).

Space complexity is O(1).

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxp = float('-inf')
        for i in range(len(prices)-1):
            for j in range(i+1, len(prices)):
                if prices[j] - prices[i] > maxp:
                    maxp = prices[j] - prices[i]
        return 0 if maxp == float('-inf') or maxp < 0 else maxp
```

### DP
We don't have to check for all pairs of buying and selling days, for any specific day `i` , the maximum profit we can get when selling on day `i` is by taking price on day `i` minus minimum price of days from 0 to `i-1` inclusive.

```
max_profit(i) = prices[i] - min(prices[:i])
```

#### Top-down
```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        def find(i):
            if i == 0:
                return 0
            return max(prices[i] - min(prices[:i]), find(i-1))
        
        return find(len(prices)-1)
```

#### Top-down improvement
We can see that the bottleneck here is calculating minimum price of previous days of a certain day.

We can improve it by precomputing min price and only re-calculate it only when the current price is the min price.

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # reduce time spending finding min_price by gradually reduce it by current price
        def find(i, min_price):
            if i == 0:
                return 0
            
            # if current price is the min_price, then current profit is 0, 
            # find a new min_price of previous days
            if prices[i] == min_price:
                return max(0, find(i-1, min(prices[:i])))

            # otherwise, re-use min_price
            return max(prices[i] - min_price, find(i-1, min_price))
        
        return find(len(prices)-1, min(prices))
```

#### Bottom-up
**Analysis**

We only use single iteration so time complexity is O(n).

Space complexty is O(1).

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = prices[0]
        max_profit = 0
        for i in range(1, len(prices)):
            # update max_profit if current prodit is larger
            if prices[i] - min_price > max_profit:
                max_profit = prices[i] - min_price
            # update min_price for next one
            if prices[i] < min_price:
                min_price = prices[i]
        return max_profit
```

```
210 / 210 test cases passed.
Status: Accepted
Runtime: 1108 ms
Memory Usage: 25 MB
```

## Problem 2
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

### Brute Force
For a certain day `i`, there are 3 possibilities

1. It's a resting day, so the maximum profit is by buying and selling from day 0 to day `i-1`.
2. It's a selling day, so the maximum profit is addition of profit when selling on day `i` and what we need to find is the day to buy that selling on day `i` make most profitable.

In conclusion, we have following formular:

```
profits[i] = max(profits[i-1], profits[i-2], max(prices[i] - prices[j] + profits[j-2] for j from 0 to i-1))
```

**Analysis**

Each recursive take O(n) operations, and there are also O(n) recursions, so time complexity is O(n^n) overall.

Space complexity is O(n) for recursive stack.

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        # i is the selling day.
        def find(i):
            if i <= 0:
                return 0
            
            # if day i is a resting day
            max_profit = find(i-1)
            # else day i is a selling day,
            # try to find the max profit by selecting buying day is one of previous days
            for j in range(0, i):
                p = max(0, prices[i] - prices[j]) + find(j-2)  # minus 2 due to 1 day cooldown
                if p > max_profit:
                    max_profit = p
            return max_profit
        
        return find(n-1)
```

### Topdown with Memorization
We can see the overlapping problem when `find(i)` is being called many times with the same value `i`.

For example

```
prices: [1,2,3,0,2]

With i = 4:
    - find(i-1) = find(3)
    - find(j-2) = find(-2), find(-1), find(0), find(1)
With i = 3:
    - find(i-1) = find(2)
    - find(j-2) = find(-2), find(-1), find(0)
...
```

To avoid calculating maximum profit over and over for a certain day i, we use memorization to keep maximum profit and re-use it later.


```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        # i is the selling day.
        def find(i):
            if i <= 0:
                return 0
            
            if profits[i] != -1:
                return profits[i]
            
            # if day i is a resting day
            max_profit = find(i-1)
            # else day i is a selling day,
            # try to find the max profit by selecting buying day is one of previous days
            for j in range(0, i):
                p = max(0, prices[i] - prices[j]) + find(j-2)  # minus 2 due to 1 day cooldown
                if p > max_profit:
                    max_profit = p
                    
            profits[i] = max_profit
            return max_profit
        
        profits = [-1 for _ in prices]
        return find(n-1)
```
```
210 / 210 test cases passed.
Status: Accepted
Runtime: 3096 ms
Memory Usage: 18.9 MB
```

### Bottom-up

**Analysis**

Two loops consume the most running time so time complexity is O(n^2).

Space complexity is O(n) due to storing list of profits.

```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)

        if n == 1:
            return 0
        
        # profits[i] is the maximum profit we can get so far till day i (sell at day i)
        profits = [-1 for _ in range(n)]
        profits[0] = 0
        profits[1] = max(0, prices[1] - prices[0])
        
        for i in range(2, n):
            # if day i is a resting day
            max_profit = max(profits[i-1], profits[i-2])
            # day i is a selling day
            for j in range(0, i):
                # profits[j-2] due to skip cooldown day
                p = max(0, prices[i] - prices[j]) + (profits[j-2] if j - 2 >= 0 else 0)
                if p > max_profit:
                    max_profit = p
            profits[i] = max_profit
            
        return profits[n-1]
```

```
210 / 210 test cases passed.
Status: Accepted
Runtime: 2328 ms
Memory Usage: 14.7 MB
```
## Problem 3
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/


### Brute Force
The brute force approach is similar to problem 2, except we keep counting number of used transactions to discard any choices that exceed k.

```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        def find(i, kt):
            if i <= 0:
                return 0
			# if more than k transaction have been made, we stop making any transactions
            if kt > k:
                return 0
			# i might be a rest day
            mp = find(i-1, kt)
            for j in range(0, i):
			    # i is a selling day, looking for a buying day
                mp = max(mp, prices[i] - prices[j] + find(j-1, kt+1))
            return mp

        return find(len(prices)-1, 1)
```

### DP
Let's call dp[i][j] is a maximum profit at day j with i transactions.

- If day j is a resting day, then dp[i][j] = dp[i][j-1]
- If day j is a selling day, then we will looking for a buying day j' that `dp[i][j] = dp[i-1][j'-1] + (prices[j] - prices[j'])` is a maximum profit.


```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        dp = [[0 for _ in range(n+1)] for _ in range(k+1)]
        prices = [0] + prices
        
        for i in range(1, k+1):
            for j in range(1, n+1):
                # init dp[i][j] is a maximum profit if j is a resting day
                dp[i][j] = dp[i][j-1]
                # day j is a selling day, pick day j' that maximum profit
                for jj in range(1, j):
                    dp[i][j] = max(dp[i][j], prices[j] - prices[jj] + dp[i-1][jj-1])
        return dp[k][n]
```

### DP Improved

Third loop contains wasted operations due to retry and keep recording max profit. We need to find a day j' with a single operation.

Remember that in third loop, day[i][j] is the maximum profit at selling day j with i iteration, so we need to find a day j' so that `dp[i][j] = dp[i-1][j'-1] + (prices[j] - prices[j'])` is maximum. Other way to think about this is we need to find a maximum profit before day j', which is `dp[i][j'-1]`, minus with prices when buying at day j'. It means that we need to find maximum value of `dp[i-1][j'-1] - prices[j']`, because `prices[j]` is a constant, so if we find that maximum, then profit when selling at day j is maximum.

On each day, we keep recording maximum profit when at day j'-1 and buying stock at day j'.

**Analysis**
Time complexity: O(kn)
Space complexity: O(kn) due to the matrix `dp`.


```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        if n == 0:
            return 0
        
        dp = [[0 for _ in range(n)] for _ in range(k+1)]
        
        for i in range(1, k+1):
            mp = -prices[0]  # cost of buying at day 1
            for j in range(1, n):
                # maximum if day j is a resting day or selling day
                dp[i][j] = max(dp[i][j-1], mp + prices[j])
                # update max profit if buying at day j
                mp = max(mp, dp[i-1][j-1] - prices[j])
            
        return dp[k][n-1]
```
```
211 / 211 test cases passed.
Status: Accepted
Runtime: 180 ms
Memory Usage: 15.5 MB
```
