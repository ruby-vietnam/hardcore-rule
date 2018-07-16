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

Problem 2:

https://www.hackerrank.com/challenges/sparse-arrays/problem

```go
func matchingStrings(strings []string, queries []string) (r []int32) {
    qMap := make(map[string]int32)
    for _, q := range queries {
        qMap[q] = 0
    }
    for _, s := range strings {
        if c, ok := qMap[s]; ok {
            qMap[s] = c + 1
        }
    }
    for _, q := range queries {
        r = append(r, qMap[q])
    }
    return
}
```
