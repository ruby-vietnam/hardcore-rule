# Problem 1

```golang
func isPowerOfThree(n int) bool {
    if n <= 0 {
        return false
    }   
    return int64(math.Pow(3, 19)) % int64(n) == 0
}
```