# Easy
> [1812. Determine Color of a Chessboard Square](https://leetcode.com/problems/determine-color-of-a-chessboard-square/)

**Approach 1:**

Explanation:
- simple check array of black one, else is the white

Analysis:
- Time complexity: O(1)
- Space complexity: O(1)

Submission Detail
```
Status:
203 / 203 test cases passed.
Runtime: 16 ms
Memory Usage: 13.4 MB
```

```python
class Solution(object):
    def squareIsWhite(self, coordinates):
        """
        :type coordinates: str
        :rtype: bool
        """
        if coordinates in [
            'a1', 'a3', 'a5', 'a7',
            'b2', 'b4', 'b6', 'b8',
            'c1', 'c3', 'c5', 'c7',
            'd2', 'd4', 'd6', 'd8',
            'e1', 'e3', 'e5', 'e7',
            'f2', 'f4', 'f6', 'f8',
            'g1', 'g3', 'g5', 'g7',
            'h2', 'h4', 'h6', 'h8'
        ]:
            return False

        return True
```

**Approach 2:**

Explanation:
- transfer char to number by it index
- sum of number or char and the other will % 2 == 0 => black
- else, white

Analysis:
- Time complexity: O(1)
- Space complexity: O(1)

Submission Detail
```
Status:
203 / 203 test cases passed.
Runtime: 16 ms
Memory Usage: 13.4 MB
```

```python
class Solution(object):
    def squareIsWhite(self, coordinates):
        """
        :type coordinates: str
        :rtype: bool
        """
        chars = 'abcdefgh'
        n_char = 0

        if coordinates[0] in chars:
          n_char = chars.index(coordinates[0]) + 1

        if (n_char + int(coordinates[1])) % 2 == 0:
            return False

        return True
```

# Medium
> [935. Knight Dialer](https://leetcode.com/problems/knight-dialer/)

**Approach 1(TLE):**

Explanation:
> Các khả năng con mã có thể đi cho tất cả các ô trên điện thoại là:
- Số 0 -> đi tới 4 hoặc 6
- Số 1 -> đi tới 6 hoặc 8
- Số 2 -> đi tới 7 hoặc 9
- Số 3 -> đi tới 4 hoặc 8
- Số 4 -> đi tới 0 hoặc 3 hoặc 9
- Số 5 -> không có vị trí nào
- Số 6 -> đi tới 0 hoặc 1 hoặc 7
- Số 7 -> đi tới 2 hoặc 6
- Số 8 -> đi tới 1 hoặc 3
- Số 9 -> đi tới 2 hoặc 4

Mình lập được một dict chứa các khả năng tương ứng với các vị trí theo index như sau:
```
index    0       1      2       3         4       5      6        7.       8.      9
     [[4, 6], [6, 8], [7, 9], [4, 8], [0, 3, 9], [], [0, 1, 7], [2, 6], [1, 3], [2, 4]]
```

Analysis:
- Time complexity: O()
- Space complexity: O()

Submission Detail
```
Status:
x / x test cases passed.
Runtime: x ms
Memory Usage: x MB
```

```python
class Solution(object):
    def knightDialer(self, n):
        """
        :type n: int
        :rtype: int
        """
        patchs = [[4, 6], [6, 8], [7, 9], [4, 8], [0, 3, 9], [], [0, 1, 7], [2, 6], [1, 3], [2, 4]]


    def find_choice(self, n):
        cells = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
        potentials =
        choices = []

        if n == 1:
            return cells


        choices_before_n = self.find_choice(n-1)
        for choice in choices_before_n:
            connect = choice[len(choice) - 1]
            for p in potentials[int(connect)]:
                choices.append("{}{}".format(choice, p))

        return choices

```

**Approach 2(Accepted):**

Explanation:

> Các khả năng con mã có thể đi cho tất cả các ôn trên điện thoại là:
- Số 0 -> đi tới 4 hoặc 6
- Số 1 -> đi tới 6 hoặc 8
- Số 2 -> đi tới 7 hoặc 9
- Số 3 -> đi tới 4 hoặc 8
- Số 4 -> đi tới 0 hoặc 3 hoặc 9
- Số 5 -> không có vị trí nào
- Số 6 -> đi tới 0 hoặc 1 hoặc 7
- Số 7 -> đi tới 2 hoặc 6
- Số 8 -> đi tới 1 hoặc 3
- Số 9 -> đi tới 2 hoặc 4

> Phân tích DP:

**Với i = 1, có 10 khả năng ngựa có thể đi là bạn ấy đứng lần lượt các ô từ 0 đến 9**

dp[0][0] = dp[0][1] = dp[0][2] =. dp[0][3] = dp[0][4] = dp[0][5] = dp[0][6] = dp[0][7] = dp[0][8] = dp[0][9] = 1

dp[0] = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

**Với i = 1,  ngựa có thể đứng ở các ô từ 0 đến 9 rồi thực hiện đi tiếp:**
```
Đứng từ 0, ngựa có thể di chuyển đến 4 hoặc 6
dp[1][0] = dp[0][4] + dp[0][6] = 1 + 1 = 2
Tương tự cho các khả năng có thể di chuyển từ các số khác mình có:
dp[1][1] = dp[0][6] + dp[0][8] = 1 + 1 = 2
dp[1][2] = dp[0][7] + dp[0][9] = 1 + 1 = 2
dp[1][3] = dp[0][4] + dp[0][8] = 1 + 1 = 2
dp[1][4] = dp[0][0] + dp[0][3] + dp[0][9] = 1 + 1 + 1 = 3
dp[1][5] = 0
dp[1][6] = dp[0][0] + dp[0][1] + dp[0][7] = 1 + 1 + 1 = 3
dp[1][7] = dp[0][2] + dp[0][6] = 1 + 1 = 2
dp[1][8] = dp[0][1] + dp[0][3] = 1 + 1 = 2
dp[1][9] = dp[0][2] + dp[0][4] = 1 + 1 = 2
```

-> Tổng số khả năng có thể với N=2 là: sum(dp[1]) = 2 + 2 + 2 + 2 + 3 + 0 + 3 + 2 + 2 + 2 = 20

Rút ra được công thức với i:
```
dp[i][0] = dp[i-1][4] + dp[i-1][6]
dp[i][1] = dp[i-1][6] + dp[i-1][8]
dp[i][2] = dp[i-1][7] + dp[i-1][9]
dp[i][3] = dp[i-1][4] + dp[i-1][8]
dp[i][4] = dp[i-1][0] + dp[i-1][3] + dp[i-1][9]
dp[i][5] = 0
dp[i][6] = dp[i-1][0] + dp[i-1][1] + dp[i-1][7]
dp[i][7] = dp[i-1][2] + dp[i-1][6]
dp[i][8] = dp[i-1][1] + dp[i-1][3]
dp[i][9] = dp[i-1][2] + dp[i-1][4]
```

-> Tổng số khả năng với N = i là sum(dp[i])


Analysis:
- Time complexity: O()
- Space complexity: O()

Submission Detail
```
Status:
121 / 121 test cases passed.
Runtime: 456 ms
Memory Usage: 13.5 MB
```

```python
class Solution(object):
    def knightDialer(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
        modulo = 10**9 + 7

        for i in range(2, n + 1):
            dp_before = dp[::]

            dp[0] = dp_before[4] + dp_before[6]
            dp[1] = dp_before[6] + dp_before[8]
            dp[2] = dp_before[7] + dp_before[9]
            dp[3] = dp_before[4] + dp_before[8]
            dp[4] = dp_before[0] + dp_before[3] + dp_before[9]
            dp[5] = 0
            dp[6] = dp_before[0] + dp_before[1] + dp_before[7]
            dp[7] = dp_before[2] + dp_before[6]
            dp[8] = dp_before[1] + dp_before[3]
            dp[9] = dp_before[2] + dp_before[4]

        result = sum(dp) % modulo

        return result
```

# Hard
> [51. N-Queens](https://leetcode.com/problems/n-queens/)

**Approach 1:**

Explanation:
-

Analysis:
- Time complexity: O()
- Space complexity: O()

Submission Detail
```
Status:
x / x test cases passed.
Runtime: x ms
Memory Usage: x MB
```

```python
``