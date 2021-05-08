# [1812. Determine Color of a Chessboard Square](https://leetcode.com/problems/determine-color-of-a-chessboard-square/)

## Approach

**Algorithm:**
- Convert column index to number (start with 1)
- If column index and row index are both odds or evens, the square is black. Otherwise, it's white.

**Analysis:**
- Time complexity: `O(1)`
- Space complexity: `O(1)`

**Submission Detail:**
```cpp
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int col = coordinates[0] - 'a' + 1;
        int row = coordinates[1];
        if ((col & 1) == (row & 1)) {
            return false;
        }
        return true;
    }
};
```
```
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Determine Color of a Chessboard Square.
Memory Usage: 5.8 MB, less than 85.64% of C++ online submissions for Determine Color of a Chessboard Square.
```

# [935. Knight Dialer](https://leetcode.com/problems/knight-dialer/)

**Submission Detail:**
```cpp
class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }
        long mod = 1e9 + 7;
        vector<unsigned int> c(10, 1);
        vector<unsigned int> tmp;
        unsigned int result = 0;
        c[5] = 0;
        for (auto i=0; i<n-1; ++i) {
            tmp.assign(c.begin(), c.end());
            c[0] = (tmp[4] + tmp[6]) % mod;
            c[1] = (tmp[6] + tmp[8]) % mod;
            c[2] = (tmp[7] + tmp[9]) % mod;
            c[3] = (tmp[4] + tmp[8]) % mod;
            c[4] = (tmp[3] + tmp[9] + tmp[0]) % mod;
            c[6] = (tmp[1] + tmp[7] + tmp[0]) % mod;
            c[7] = (tmp[2] + tmp[6]) % mod;
            c[8] = (tmp[1] + tmp[3]) % mod;
            c[9] = (tmp[2] + tmp[4]) % mod;
        }
        for (auto i=0; i<10; ++i) {
            result = (result + c[i]) % mod;
        }
        return result;
    }
};
```
```
Runtime: 24 ms, faster than 91.74% of C++ online submissions for Knight Dialer.
Memory Usage: 5.8 MB, less than 99.46% of C++ online submissions for Knight Dialer.
```
