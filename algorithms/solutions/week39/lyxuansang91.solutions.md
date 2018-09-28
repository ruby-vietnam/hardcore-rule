# Problem 1 - [Reverse Integer](https://leetcode.com/problems/reverse-integer/description/)

```go
func reverse(x int) int {
    sign := 1
    if x < 0 {
        sign = -1
        x = -x
    }
    res := 0
    for x > 0 {
        res = 10* res + x % 10
        x/= 10
    }
    if res > 2147483647 {
        return 0
    }
    if sign == -1 {
        return -res
    }
    return res
}
```

# Problem 2 - [Word Search](https://leetcode.com/problems/word-search/description/)

Using DFS ([Depth-first search](https://en.wikipedia.org/wiki/Depth-first_search))

```go
func dfs(board [][]byte, x,y int, word string,vs [][]bool, idx int) bool {
    if board[x][y] != word[idx] {
        return false
    }
    
    if idx == len(word)-1 {
        return true
    }

    dx, dy := []int{1, 0, -1, 0}, []int{0, 1, 0, -1}
    m,n := len(board),len(board[0])
    vs[x][y] = true
    res := false
    for i := 0; i < 4; i++ {
        xx, yy := x + dx[i], y + dy[i]
        if xx >= 0 && xx < m && yy >= 0 && yy < n && !vs[xx][yy] {
            if !res && dfs(board, xx, yy, word, vs, idx + 1) {
                res = true
                break
            }
        }
    }
    vs[x][y] = false
    return res
}

func exist(board [][]byte, word string) bool {
    if len(word) == 0 {
        return true
    }
    m := len(board)
    if m == 0 {
        return false
    }
    n := len(board[0])
    if n == 0 {
        return false
    }
    vs := make([][]bool, m)
    for i := 0; i < m; i++ {
        vs[i] = make([]bool, n)
    } 
    for i := range board {
        for j := range board[i] {
            if board[i][j] == word[0] {
                if dfs(board, i,j, word, vs, 0) {
                    return true
                }
            }
        }
    }
    return false
}
```

# Problem 3 - [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/description/)

Let S(i) = (a(1) + a(2) + ... + a(i)) % K (i <= n).

If we have (i,j) and S(i) == S(j) && j-i >= 1 then return true otherwise return false.

Time complexity: O(N).
  
```go
func checkSubarraySum(nums []int, k int) bool {
    mMap := map[int]int{}
    sum := 0
    for i := range nums {
        sum += nums[i]
        if k != 0 {
            sum = (sum + k) % k
        }
        if sum == 0 && i > 0 {
            return true
        }
        v, ok := mMap[sum]
        if !ok {
            mMap[sum] = i
        } else {
            if i - v > 1 {
                return true
            }
        }
    }
    return false
}
```

## Problem 4 - [Numbers At Most N Given Digit Set](https://leetcode.com/problems/numbers-at-most-n-given-digit-set/description/)

```python
class Solution:
    def atMostNGivenDigitSet(self, D, N):
        S = str(N)
        K = len(S)
        dp = [0] * K + [1]

        for i in range(K-1, -1, -1):
            # Compute dp[i]
            for d in D:
                if d < S[i]:
                    dp[i] += len(D) ** (K-i-1)
                elif d == S[i]:
                    dp[i] += dp[i+1]

        return dp[0] + sum(len(D) ** i for i in range(1, K))
```
