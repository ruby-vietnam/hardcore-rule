```go
func reverse(x int) int {
    result := 0;
    temp_result := result
    for x != 0 {
        temp_result = result
        k := x % 10
        result = result * 10 + k 
        x = x / 10
        if (result - k) / 10 != temp_result {
            return 0
        }
    }
    return result
}
```
