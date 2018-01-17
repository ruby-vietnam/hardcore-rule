## Problem 1

https://play.golang.org/p/boUxINUIn9Y

```
func getRow(rowIndex int) []int {
	result := make([]int, rowIndex+1, rowIndex+1)
	result[0] = 1
	for row := 0; row < rowIndex; row++ {
		for columnIndex := row+1; columnIndex >= 1; columnIndex-- {
			result[columnIndex] += result[columnIndex-1]
		}
	}
	return result
}
```
