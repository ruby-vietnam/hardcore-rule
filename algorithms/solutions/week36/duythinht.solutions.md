### Climbing Stairs

https://leetcode.com/problems/climbing-stairs/description/

```go
func climbStairs(n int) int {
    if n <= 2 {
        return n
    }
    w1 := 1
    w2 := 2
    for x := 3; x <= n ; x++ {
        w1, w2 = w2, w1 + w2
    } 
    return w2
}
```
