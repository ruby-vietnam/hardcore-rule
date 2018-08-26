# Problem 2

```golang
func spiralMatrixIII(R int, C int, r0 int, c0 int) [][]int {
	directions := [4][2]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
	totalStep := R * C
	result := make([][]int, totalStep)
	result[0] = []int{r0, c0}
	step := 1
	curr := 0
	edge := 0
	for step < totalStep {
		if curr % 2 == 0 {
			edge++
		}
		for i := 0; i < edge; i++ {
			r0 += directions[curr][0]
			c0 += directions[curr][1]
			if r0 >= 0 && r0 < R && c0 >= 0 && c0 < C {
				result[step] = []int{r0, c0}
				step++
			}
		}
		curr = (curr + 1) % 4
	}
	return result
}
```