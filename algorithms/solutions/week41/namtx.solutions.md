## Problem 1

```go
func singleNumber(nums []int) int {
    var ret int
    for _, x := range nums {
        ret ^= x
    }
    return ret
}
```

## Problem 2

```go
func countSubstrings(s string) int {
  size := len(s)
  count := 0
  dp := make([][]int, size)
  for i := range dp {
    dp[i] = make([]int, size)
  }

  for i := 0; i < size; i++ {
    dp[i][i] = 1
    for j := 0; j < i; j++ {
      if s[i] == s[j] {
        if i-j == 1 {
          dp[j][i] = 1
          count++
        } else {
          if dp[j+1][i-1] != 0 {
            count++
            dp[j][i] = dp[j+1][i-1] + 2
          } else {
            dp[j][i] = 0
          }
        }
      }
    }
  }
  return count + len(s)
}
```
