# 1. (Ease) [# 1. (Ease) [190. Reverse Bits](https://leetcode.com/problems/reverse-bits)
## Approach:
### 1.1 Solution
- Python built-in function to convert to binary, and reverse with slice

### 1.2 Code
```python
class Solution:
    def reverseBits(self, n: int) -> int:
        # chuyển số nguyên về số nhị phân
        # n_binary_str = bin(n).replace("0b", "")
        n_binary_str = "{0:b}".format(n)

        # thêm số 0 cho đủ 32 bit
        while len(n_binary_str) < 32:
            n_binary_str = "0" + n_binary_str

        # đảo ngược thứ tự
        n_binary_str = n_binary_str[::-1]

        # chuyển nhị phân về số nguyên
        return int(n_binary_str, 2)
```
