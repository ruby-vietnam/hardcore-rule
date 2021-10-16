# Session4 - Week5

1. Pascal Triangle

```go
func generate(numRows int) [][]int {
	result := make([][]int, numRows)

	result[0] = []int{1}
	for i := 1; i < numRows; i++ {
		result[i] = make([]int, i+1)
		for j := 0; j < i+1; j++ {
			if j == 0 || j == i {
				result[i][j] = result[i-1][i-1]
			} else {
				result[i][j] = result[i-1][j-1] + result[i-1][j]
			}
		}
	}

	return result
}
```

2. Pascal Triangle II

```go
func getRow(rowIndex int) []int {
	result := make([][]int, rowIndex+1)

	result[0] = []int{1}
	for i := 1; i < rowIndex+1; i++ {
		result[i] = make([]int, i+1)
		result[i][0], result[i][i] = 1, 1
		for j := 1; j < i; j++ {
			result[i][j] = result[i-1][j-1] + result[i-1][j]
		}
	}

	return result[rowIndex]
}
```

3. Triangle

```go
func minimumTotal(triangle [][]int) int {
	length := len(triangle)
	for i := 1; i < len(triangle); i++ {
		triangle[i][0], triangle[i][i] = triangle[i][0]+triangle[i-1][0], triangle[i][i]+triangle[i-1][i-1]
		for j := 1; j < i; j++ {
			triangle[i][j] = triangle[i][j] + min(triangle[i-1][j-1], triangle[i-1][j])
		}
	}

	minValue := triangle[length-1][0]
	for i := 1; i < len(triangle[length-1]); i++ {
		minValue = min(minValue, triangle[length-1][i])
	}

	return minValue
}

func min(x, y int) int {
	if x < y {
		return x
	}

	return y
}
```
