# Easy
> [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

**Approach 1(TLE):**

Explanation: Tìm hai số ở vị trí i, j với i < j và A[j] - A[i] là lớn nhất

- Khởi tạo profit là 0
- Duyệt qua list A lần lượt với i là chỉ số index, n là giá trị A[i]
  - Duyệt qua list còn lại từ vị trí i là A[i:] với j là chỉ số index, m là giá trị A[j]
    - Nếu m > n và profit < m - n thì gán profit = m - n

profit sẽ có giá trị lớn nhất

Analysis:
- Time complexity: O(n^2)
- Space complexity: O(n^2)

Submission Detail
```
Status:
198 / 210 test cases passed.
Runtime: ms
Memory Usage:  MB
```

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0
        for i, n in enumerate(prices):
            for j, m in enumerate(prices[i:]):
                if m > n and profit < m - n:
                    profit = m - n

        return profit
```

**Approach 2(Accepted):**

Dùng 2 con trỏ và một set chứa các giá trị profits:
- 1 con là buy(với giá trị ban đầu là giá đầu tiên trong list prices)
- 1 con là sell(với giá trị ban đầu là 0)
- 1 set các giá trị profits valid
> Duyệt qua mảng prices
- Nếu buy > n và n không phải giá trị cuối cùng thì gán buy = n, và sell = 0 vì khi mua thì reset sell
- Nếu buy < n thì gán sell = n, khi update sell thì add profit vào set profits với giá trị sell - buy
> -> max profit là max của set profits

```
ví dụ: [7, 1, 3, 5, 6]
price : 7 1 3 5 6
buy   : 7 1 1 1 1
sell  : 0 0 3 5 6
profit: 0 0 2 4 5 -> max = 5

ví dụ: [2, 1, 2, 0, 1]
price : 2 1 2 0 1
buy   : 2 1 1 0 0
sell  : 0 1 2 0 1
profit: 0 0 1 0 1 -> profits={1}

ví dụ: [7, 2, 5, 0, 1, 2]
price : 7 2 5 0 1 2
buy   : 7 2 2 0 0 0
sell  : 0 0 5 0 1 2
profit: 0 0 3 0 1 2 -> profits={3, 1, 2} -> max = 3

ví dụ: [7, 2, 5, 0, 1, 5]
price : 7 2 5 0 1 2
buy   : 7 2 2 0 0 0
sell  : 0 0 5 0 1 5
profit: 0 0 3 0 1 5 -> profits={3, 1, 5} -> max = 5
```

Analysis:
- Time complexity: O()
- Space complexity: O()

Submission Detail
```
Status:
210 / 210 test cases passed.
Runtime: 772ms
Memory Usage:  22.5MB
```

```python

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        buy = prices[0]
        sell = 0
        profits = set()

        for i, n in enumerate(prices):
            # buy could not be the last item
            # buy updated -> sell = 0
            if buy > n and i != len(prices) - 1:
                buy = n
                sell = 0

            elif sell < n:
                sell = n
                if sell > buy:
                    profits.add(sell - buy)

        return max(profits) if len(profits) else 0
```


# Medium
> [309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

**Approach:**
Explanation:

Analysis:
- Time complexity:
- Space complexity:
Submission Detail
```
Status:
x / x0 test cases passed.
Runtime: ms
Memory Usage:  MB
```

```python
```

# Hard
> [3188. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)


**Approach:**
Explanation:

Analysis:
- Time complexity:
- Space complexity:
Submission Detail
```
Status:
x / x0 test cases passed.
Runtime: ms
Memory Usage:  MB
```

```python
```
