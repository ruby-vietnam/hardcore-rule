## Problem 1

```go
func getRow(rowIndex int) []int {
    result := make([]int, rowIndex+1, rowIndex+1)
    result[0] = 1
    for rowSeeking := 1; rowSeeking < rowIndex+1; rowSeeking++ {
        for j := rowSeeking; j >= 1; j-- {
            result[j] += result[j-1]
        }
    }
    return result
}
```
