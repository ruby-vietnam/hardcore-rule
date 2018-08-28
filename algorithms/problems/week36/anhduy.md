# 70

```go
func climbStairs(n int) int {
    if n == 1 {
        return 1        
    }

    if n == 2 {
        return 2
    }
    
    x0 := 0
    x1 := 1
    x2 := 2
    for i := 3; i <= n; i++ {
        x0 = x1
        x1 = x2
        x2 = x0 + x1;
    }
    
    return x2
}
```

