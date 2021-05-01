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
### Explanation:
> Phân tích đề:
>
> Khi chưa có cổ phiếu, mình sẽ đi mua hoặc đợi(không mua)
>
> Khi có cổ phiếu, mình sẽ đi bán, hoặc đợi(giữ cp)
>
> Sau khi bán, có 1 ngày cool down thì ngày đó sẽ đợi(không được mua)

> Do đó, tại một ngày bất kỳ, sẽ có 3 khả năng có thể xảy ra: Mua, Bán, Đợi

* Quy bài toán theo các trạng thái, tạo sơ đồ:

> Giả sử tại một ngày bất kỳ mình chưa có cổ phiếu: [X]
>
> [X] -> tại đây xảy ra hai khả năng là mua hoặc không mua
>
> Nếu tại X mua, chuyển trạng thái qua ngày [Y]
>
> [Y] -> tại đây xảy ra hai khả năng là bán hoặc giữ không bán(đợi)
>
> Nếu tại [Y] bán, chuyển trạng thái qua ngày [Z], tại đây có một ngày cooldown nên bắt buộc phải đợi
>
**Ta có được sơ đồ các khả năng mua, bán, đợi trong ba trạng thái [X], [Y], [Z] có thể xảy ra:**

```
      |-------------Đợi-----------------------|
      |                                       |
      |-> [X]  -> Mua -> [Y] -> Bán -> [Z] -> |
        |  ^           |  ^
        |--|           |--|
        Đợi           Đợi
```

Lập bảng giải bài toán bằng quy hoạch động với n là số ngày giao dịch, và 3 khả năng xảy ra X, Y, Z như trên

```
Ví dụ: [7, 2, 5, 0, 1, 2]

n      0  1. 2. 3. 4. 5
price  7  2  5  0  1  2
X      0  0  0  3  3  3
Y     -7 -2 -2  0  2  4
Z      0 -5  3 -2  1  4
```

Giá bán có lợi nhất là max của X, Y, Z cot so 5 -> **4**


#### **Cong thuc tong quat tinh X_n, Y_n, Z_n**

> **Tại vị trí X**: chọn giữ trạng thái Z_n-1 hoặc chọn giữ từ X_n-1
>
> `X_n = max(X_n-1, Z_n-1)`
>
> **Tại vị trí Y**: chọn giữ trạng thái Y_n-1 hoặc chọn mua từ X_n-1. Nếu mua(mất bớt tiền -> -) thì profit sẽ là giá X_n-1 - price_n
>
> `Y_n = max(Y_n-1, X_n-1 - price_n)`
>
> **Tại vị trí Z**: bán(thêm tiền -> +) từ giá trị Y_n-1 -> Y_n-1 + price_n
>
> `Z_n = max(Y_n-1 + price_n)`
>
> `Lợi nhuận tối ưu là: max(X_n, Y_n, Z_n) với n là thứ tự cuối cùng của prices`


Analysis:
- Time complexity:
- Space complexity:

Submission Detail
```
Status:
210 / 210 test cases passed.
Runtime: 44 ms
Memory Usage:  13.9 MB
```

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        length = len(prices)

        if length < 2 or length == 2 and prices[0] > prices[1]:
            return 0

        A = []
        for p in prices:
            A.append([0,0,0])

        # First day
        A[0][0] = 0
        A[0][1] = 0 - prices[0]
        A[0][2] = 0

        # Next days
        for i, n in enumerate(prices):
            if i > 0:
                A[i][0] = max(A[i-1][0], A[i-1][2])
                A[i][1] = max(A[i-1][1], A[i-1][0] - n)
                A[i][2] = A[i-1][1] + n

        return max(A[length-1][0], A[length-1][1], A[length-1][2])
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
 /  test cases passed.
Runtime:  ms
Memory Usage:   MB
```

```python
```
