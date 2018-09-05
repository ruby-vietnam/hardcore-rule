## Problem 1
https://leetcode.com/problems/climbing-stairs/description/

```go
func climbStairs(n int) int {
    switch n {
    case 0: return 0
    case 1: return 1
    case 2 : return 2
    default:
        n1, n2, n3 := 1, 2, 0
        for i := 2; i < n ; i ++ {
            n3 = n1 + n2
            n1 = n2
            n2 = n3
        }
        return n3
    }

    return 0
}
```
