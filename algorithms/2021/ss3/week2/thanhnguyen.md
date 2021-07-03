# 1. (Easy) [202. Happy Number](https://leetcode.com/problems/happy-number/)
## 1.1 First approach: Summary
Cách tính số tiếp theo:
- Chia nhỏ số lấy digits, cứ thực hiện khi n > 0
- Số tiếp theo chính là tổng của bình phương digit
Kiểm tra:
- Thực hiện lưu các số tính được(tiếp theo) vào một set(),
- Nếu gặp lại số đã lưu tức là nó đã đi thành vòng tròn, thoát khỏi vòng lặp
- và trả về boolean n == 1

## 1.2 First approach: Code
```python
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        def get_next(n):
            sum = 0
            while n > 0:
                n, digit = divmod(n, 10)
                sum += digit ** 2
            return sum

        seen = set()
        while n != 1 and n not in seen:
            seen.add(n)
            n = get_next(n)

        return n == 1

```
# 2. (Medium)[1415. The k-th Lexicographical String of All Happy Strings of Length n](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/)

## 2.1. First approach: Summary
**Phân tích DP:**
```
Với n = 1, có 3 khả năng lần lượt là 'a', 'b', 'c'
dp[0] = ['a', 'b', 'c']

Với n = 2, có thể từ n = 1 và lần lượt thêm các giá trị vào sao cho theo
thứ tự alphabet và không trùng với chữ phía trước
Tức lặp qua các giá trị của dp[0]
và kiểm tra ký tự kết thúc có thể đi tiếp với chữ nào, theo thứ tự:
- Nếu kết thúc với 'a' thì có hai khả năng đi tiếp là 'b', 'c'
- Nếu kết thúc với 'b' thì có hai khả năng đi tiếp là 'a', 'c'
- Nếu kết thúc với 'c' thì có hai khả năng đi tiếp là 'a', 'b'

dp[0][0] là 'a'
dp[1][0] = [
    dp[0][0] + 'b',
    dp[0][0] + 'c'
]

dp[0][1] là 'b'
dp[1][1] = [
    dp[0][1] + 'a',
    dp[0][1] + 'c'
]
dp[0][2] là 'c'
dp[1][2] = [
    dp[0][2] + 'a',
    dp[0][2] + 'b'
]

flat các giá trị trên lại:
dp[1] = ['ab', 'ac', 'ba', 'bc', 'ca', 'cb']

Với n = 3
Tương tự, lặp qua các giá trị của dp[1],
và kiểm tra ký tự kết thúc có thể đi tiếp với chữ nào, ta được
dp[2] = [
  ['aba', 'abc'],
  ['aca', 'acb'],
  ['bab', 'bac'],
  ['bca', 'bcb'],
  ['cab', 'cac'],
  ['cba', 'cbc']
]

Rút ra công thức với i:

for index, value in dp[i-1]:
  if value end with 'a':
    dp[i] = [value + 'b', value + 'c']
  if value end with 'b':
    dp[i] = [value + 'a', value + 'c']
  if value end with 'c':
    dp[i] = [value + 'a', value + 'b']

Sau đó flat dp
Và giá trị tại vị trí k là dp[k-1]
```

## 2.1. First approach: Code

```python
import itertools

class Solution(object):
    def getHappyString(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        dp = ['a', 'b', 'c']

        if n > 1:
            for i in range(2, n + 1):
                dp_before = dp[::]

                for j, c in enumerate(dp_before):
                    if c.endswith("a"):
                        dp[j] = [c + "b", c + "c"]
                    elif c.endswith("b"):
                        dp[j] = [c + "a", c + "c"]
                    elif c.endswith("c"):
                        dp[j] = [c + "a", c + "b"]

                dp = list(itertools.chain(*dp))

        if k - 1 < len(dp):
            return dp[k - 1]

        return ''

```