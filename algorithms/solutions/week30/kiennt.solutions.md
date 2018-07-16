# Problem 1

```go
// Complete the miniMaxSum function below.
func miniMaxSum(arr []int32) {
    size := len(arr)
    if size == 0 {
        fmt.Println(0, 0)
        return
    }    
    
    // find min
    min := arr[0]
    for i := 1; i < size; i++ {
        if arr[i] < min {
            min = arr[i]
        }
    }
    
    // find max
    max := arr[0]
    for i := 1; i < size; i++ {
        if arr[i] > max {
            max = arr[i]
        }
    }    
    
    // calculate sum
    var sum int64
    for _, a := range arr {
        sum += int64(a)
    }
    
    fmt.Println(sum - int64(max), sum - int64(min))
}
```