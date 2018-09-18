##Problem 1

```go
func reverse(x int) int {
    var ans int64 = 0
    var neg bool
    
    if (x < 0){
        x = -x
        neg = true
    }
    for (x > 0){
        ans = ans*10 + int64(x%10)
        x /= 10
    }
    
    if (ans > 2147483647){
        return 0
    }
    
    if (neg){ 
        ans = -1*ans
    }
    
    return int(ans)
}
```
