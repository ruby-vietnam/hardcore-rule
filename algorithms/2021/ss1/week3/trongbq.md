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

1. It's a cooldown day, so the maximum profit is by buying and selling from day 0 to day `i-1`.
2. It's a selling day, so the maximum profit is addition of profit when selling on day `i` and what we need to find is the day to buy that selling on day `i` makes most profitable.

In conclusion, we have following formular:

```
profits[i] = max(profits[i-1], max(prices[i] - prices[j] + profits[j-2] for j from 0 to i-1))
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
            
            # if day i is a cooldown day
            max_profit = find(i-1)
            # try to find the max profit by selecting selling day is one of previous days
            for j in range(0, i):
                p = max(0, prices[i] - prices[j]) + find(j-2)  # minus 2 due to 1 day cooldown
                if p > max_profit:
                    max_profit = p
            return max_profit
        
        return find(n-1)
```

### Topdown with Memorization
We can see the overlapping problem when `find(i)` is being called many times.

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
            
            # if day i is a cooldown day
            max_profit = find(i-1)
            # try to find the max profit by selecting selling day is one of previous days
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
Runtime: 3140 ms
Memory Usage: 18.8 MB
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
        profits = [0] + [max(0, prices[1] - prices[0])] + [-1 for _ in range(2, n)]
        
        for i in range(2, n):
            # if day i is a cooldown day, then maximum profits is profits[i-1]
            max_profit = profits[i-1]
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
Runtime: 2356 ms
Memory Usage: 14.7 MB
```
