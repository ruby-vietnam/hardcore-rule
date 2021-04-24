# Easy
> [1046. Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)

**Approach 1:**

Explanation:
- Sort list by weight decrease
- Get 2 values from top, smash them by the rule and get return value
- Update the list with return value and repeat until the rest of list has length < 2

Rule mash is: x, y
- if x = y, destroy both
- if x < y, destroy x, y = y - x

Analysis:
- Time complexity:
- Space complexity:

Submission Detail
```
Status:
70 / 70 test cases passed.
Runtime: 20ms
Memory Usage: 13.2 MB
```

```python
class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """

        while stones and len(stones) > 1:
            # sort decrese list
            stones = self.sort_descrease(stones)
            # apply smash
            x = self.smash_two_weightest(stones[0], stones[1])
            # new list
            stones = [x] + stones[2:] if x else stones[2:]

        return stones[0] if stones else 0

    def smash_two_weightest(self, x, y):
        if x == y:
            return None
        return x - y

    def sort_descrease(self, stones):
        stones.sort(reverse=True)
        return stones

```

# Medium
> [1049. Last Stone Weight II](https://leetcode.com/problems/last-stone-weight-ii/)


## Approach 1:

Explanation:
* Quy về bài toán nhỏ hơn

> Giả sử chọn hai viên đá bất kỳ là a, b, với a > b -> a - b
>
> Lấy viên tiếp theo là c, với c > a - b -> c - (a - b) = c - a + b
>
> Lấy viên tiếp theo là d, với d > c - (a - b) -> d - (c - (a - b))
>
> = d - (c - a + b)
>
> = d - c + a - b
>
> = (d + a)  - (b + c)
>
> = (d + a + ...) - (b + c + ...)
>
> -> diff = S1 - S2 và S1 + S2 = S
>
> Vậy số bé nhất cần tìm chính là diff bé nhất
>
> diff = S1 - S2 = (S - S2) - S2 = S - (2 * S2) >= 0
>
> Để diff nhỏ nhất thì S2 phải lớn nhất, với S2 <= S // 2
>
**Quy về bài toán nhỏ hơn là:**

- Step 1: Tìm S2 sao cho S2 lớn nhất và nhỏ hơn S/2

- Step 2: Trả về diff bé nhất = S - 2 * S2
---
####  Giải bài toán nhỏ: Tìm S2 sao cho S2 lớn nhất và nhỏ hơn S//2

Bài toán này tương tự 0/1 Knapsack với:
- m = S // 2
- n = len(stones)
- weights = stones

Ví dụ stones = [2,7,4,1,8,1] thì: S = 23; m = S // 2 = 11; n = range(0,5), weights = [2,7,4,1,8,1]

- Tổng
Ta có bảng tính khởi tạo với(m=0 -> khối lượng tối đa luôn là 0):

```
      0 1 2 3 4 5 6 7 8 9 10 11 (m)
2   0 0
7   1 0
4   2 0
1   3 0
8   4 0
1   5 0
(w)(n)
```

> n = 0

```
      0 1 2 3 4 5 6 7 8 9 10 11 (m)
2   0 0 0 2 2 2 2 2 2 2 2  2  2
7   1 0
4   2 0
1   3 0
8   4 0
1   5 0
(w)(n)
```

Giải thích: với n = 0, chỉ có 1 cục đá là n0 với w_n0 là 2.

Do đó, nó sẽ có khối lượng lớn nhất là 2 cho tất cả m >=2

> n = 1
```
      0 1 2 3 4 5 6 7 8 9 10 11 (m)
2   0 0 0 2 2 2 2 2 2 2 2  2  2
7   1 0 0 2 2 2 2 2 7 7 9  9  9
4   2 0
1   3 0
8   4 0
1   5 0
(w)(n)
```

Giải thích: với n = 1, có 2 cục đá là (n0, n1) với (w_n0, w_n1) tương ứng là (2, 7).

Do đó, nó sẽ có khối lượng lớn nhất là:
- chọn được 1 viên w=2 -> tổng w=2 cho m < 7
- chọn được 1 viên w=7 -> tổng w=7 cho 7 <= m < 9
- chọn được 2 viên: w=2 và w=7 -> tổng w=9 cho 9 <= m <= 11

> n = 2
```
      0 1 2 3 4 5 6 7 8 9 10 11 (m)
2   0 0 0 2 2 2 2 2 2 2 2  2  2
7   1 0 0 2 2 2 2 2 7 7 9  9  9
4   2 0 0 2 2 4 4 6 7 7 9  9 11
1   3 0
8   4 0
1   5 0
(w)(n)
```

Giải thích: với n = 2, có 3 cục đá là (n0, n1, n2) với (w_n0, w_n1, w_n2) tương ứng là (2, 7, 4).

Do đó, nó sẽ có khối lượng lớn nhất là:
- chọn được 1 viên w=2 -> tổng w=2 cho m < 4
- chọn được 1 viên w=4 -> tổng w=4 cho 4 <= m < 7
- chọn được 1 viên w=7 -> tổng w=7 cho 7 <= m < 9
- chọn được 2 viên: w=2 và w=7 -> tổng w=9 cho 9 <= m < 11
- chọn được 2 viên w=7 và w=4  -> tổng w=11 cho m = 11


> thực hiện tương tự cho n là 3, 4, 5

```
      0 1 2 3 4 5 6 7 8 9 10 11 (m)
2   0 0 0 2 2 2 2 2 2 2 2  2  2
7   1 0 0 2 2 2 2 2 7 7 9  9  9
4   2 0 0 2 2 4 4 6 7 7 9  9 11
1   3 0 1 2 3 4 5 6 7 8 9 10 11
8   4 0 1 2 3 4 5 6 7 8 9 10 11
1   5 0 1 2 3 4 5 6 7 8 9 10 11
(w)(n)
```

Từ bảng trên ta rút ra được công thức, gọi là ct của 0/1 Knapsack(0/1 nghĩa là phần tử đó có được dùng hay không, ví dụ dùng viên w=2 thì là có, không dùng là không)

-> Công thức tổng quát: A[n, w] = max(A[n-1, w], A[n-1, w - w_of_n])

Để tính giá trị lớn nhất ở vị trí n, w thì lấy giá trị lớn nhất giữ hai gía trị:
- Giá trị của


select items:
n | weight
2 | 4
1 | 7 -> max = 11

Công thức tổng quát:

> **A[n, m] = max(A[n-1, m], A[n-1, m - w_of_n] + w_of_n)**

với:
- n là chỉ số thứ tự của viên đá
- w là khối lượng của viên đá
- w_of_n là khối lượng của viên đá thứ n


Áp dụng công thức trên thử tính là vải vị trí xem có đúng không nhé:

Giả sử bảng tính đang ở vị trí này:
```
      0 1 2 3 4 5 6 7 8 9 10 11 (m)
2   0 0 0 2 2 2 2 2 2 2 2  2  2
7   1 0 0 2 2 2 2 2 7 7 9  9  9
4   2 0 0 2 2 4 4 6 7 7 9  9 11
1   3 0 1 2 X Y
8
(w)(n)
```
Hãy thử tìm X, Y:

X = A[3, 3] = max(A[2, 3], A[2, 3 - 1] + 1) = max(2, A[2, 2] + 1) = max(2, 2 + 1) = 3

Y = A[4, 3] = max(A[3, 3], A[3, 4 - 1] + 1) = max(3, A[3, 3] + 1) = max(3, 3 + 1) = 4

-> Đúng với giá trị ở bảng trên rồi nè :D

Kết luận: số lớn nhất tìm được nằm ở vị trí A[11, 5] = 11

-> min diff = 23 - 11 * 2 = 1

---
Analysis:
- Time complexity:
- Space complexity:

Submission Detail
```
Status: Accepted
86 / 86 test cases passed.
Runtime: 68 ms
Memory Usage: 14 MB
```


```python
class Solution(object):
    def lastStoneWeightII(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """

        S = sum(stones)
        N = len(stones)

        # Tìm S2 sao cho max của S2 là S // 2
        max_S2 = S // 2
        # Khởi tạo một mảng hai chiều với cột ngang là khối lượng từ 0 đến S//2
        # cột dọc là từ 0 đến len(stones)
        A = []
        for n in stones:
            A.append([0 for w in range(max_S2 + 1)])

        # find S2 by use 0/1 Knapsack A[n, w] = max(A[n-1, w], A[n - 1, w - w_n] + w_n)
        for n in range(N):
            for w in range(S // 2 + 1):
                if w == 0:
                    A[n][w] = 0
                else:
                    last_max = A[n - 1][w]
                    new_max = A[n - 1][w - stones[n]] + stones[n] if w >= stones[n] else 0
                    A[n][w] = max(last_max, new_max)

        # S2 chính là phần tử cuối cùng của ma trận hai chiều
        S2 = A[N-1][max_S2]
        return S - 2 * S2
```