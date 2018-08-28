# Problem 1

```go
func climbStairs(n int) int {
    l := 1
    h := 1
    for i := 2; i < n + 1; i++ {
        l, h = h, l + h
    }
    return h
}
```
