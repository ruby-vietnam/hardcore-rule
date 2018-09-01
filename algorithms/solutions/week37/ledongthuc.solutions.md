Problem 1:

https://leetcode.com/problems/power-of-three/description/

```go
// 3 * 3 <=> log3(9) = 2
func isPowerOfThree(n int) bool {
    if n < 1 || n == 2{
        return false
    }
    if n == 1 || n == 3 {
        return true
    }
    v := log3(float64(n))
    if v - float64(int(v)) <= 0.000000000000009 {
        return true
    }
    return false
}

func log3(n float64) float64 {
    return math.Log(n) / math.Log(3)
}
```

```go
Another solution is checking (max_power_of_3_int % n)
```
