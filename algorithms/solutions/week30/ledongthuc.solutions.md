Problem 1:

https://www.hackerrank.com/challenges/mini-max-sum/problem

```go
func miniMaxSum(arr []int32) {
    var total int64
    min, max := int32(math.MaxInt32), int32(math.MinInt32)
    for _, i := range arr {
        if i < min {
            min = i
        }
        if i > max {
            max = i
        }
        total += int64(i)
    }
    fmt.Printf("%d %d", (total-int64(max)), (total-int64(min)))
}
```
