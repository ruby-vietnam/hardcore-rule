# Problem set 1:

```go
func findShortestSubArray(nums []int) int {    
    amap := map[int][]int{}
    min := len(nums)
    degree := 0

    for i, v := range nums {
        amap[v] = append(amap[v], i)
        if (degree < len(amap[v])) {
            degree = len(amap[v])
        }
    }

    for key := range amap {
        if len(amap[key]) != degree {
            continue
        }

        minLen := amap[key][len(amap[key]) - 1] - amap[key][0]

        if minLen < min {
            min = minLen + 1
       }
    }

    return min
}
```
