# Problem 1

```golang
func reverse(x int) int {    
    result := 0
    value := x
    for {
        if value == 0 {
            break
        }
        digit := value % 10
        value = value / 10
        result = result * 10 + digit
    }
    if result < -2147483648 || result > 2147483647 {
        return 0
    }
    return result
}
```