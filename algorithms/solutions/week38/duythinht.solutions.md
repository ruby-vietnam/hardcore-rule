# Problem 2:

This is not optimized solution

```go
func searchMatrix(matrix [][]int, target int) bool {
    for _, row := range matrix {
        for _, cell := range row {
            if target == cell {
                return true
            }
        }
    } 
    return false
}
```
