# Problem 2: [Spiral Matrix III](https://leetcode.com/problems/spiral-matrix-iii/description/)

```go
func spiralMatrixIII(R int, C int, r0 int, c0 int) [][]int {
    result := [][]int{{r0, c0}}
    x, y, n, i := 0, 1, 0, 0
    for len(result) < R * C {
        r0, c0, i = r0 + x, c0 + y, i + 1
        if 0 <= r0 && r0 < R && 0 <= c0 && c0 < C {
            result = append(result, []int{r0, c0})
        }
        if i == n / 2 + 1 {
            x, y, n, i = y, -x, n + 1, 0
        }
    }
    return result
}
```
