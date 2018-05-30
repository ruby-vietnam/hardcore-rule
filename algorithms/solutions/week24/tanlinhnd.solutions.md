# Problem 1: []()

```go
import "math"

func judgeSquareSum(c int) bool {
	n, m, tmp := 0, int(math.Sqrt(float64(c))), 0
	for n <= m {
		if tmp = n*n + m*m; tmp == c {
			return true
		} else if tmp > c {
			m--
		} else {
			n++
		}
	}
	return false
}
```
