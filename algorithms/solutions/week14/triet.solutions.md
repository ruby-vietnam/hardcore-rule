## Problem 1

Use for:

```go
func isPowerOfFour(num int) bool {
    if num == 1 {
        return true
    }
    init := 4
    for {
        if init == num {
            return true
        }
        if init > num {
            return false
        }
        init = init*4
    }
}
```
Use logarit:

```go
func isPowerOfFour(num int) bool {
    if num <= 0 {
        return false
    }
    
    if num == 1 {
        return true
    }
    log := math.Log(float64(num))/math.Log(4)
    return (math.Ceil(log) == log ) && (math.Floor(log) == log)
}
```

## Problem 2

```go

var m, n int
var dx = []int{0, 0, -1, 1}
var dy = []int{-1, 1, 0, 0}

func numIslands(grid [][]byte) int {
	m = len(grid)
	mark := make([][]int, len(grid))
	for i, row := range grid {
		mark[i] = make([]int, len(row))
	}
	count := 0
	for i, row := range grid {
		n = len(row)
		for j, col := range row {
			if col == '1' && mark[i][j] == 0 {
				count++
				search(grid, mark, i, j)
			}
		}
	}

	return count
}

func search(grid [][]byte, mark [][]int, i, j int) {
	if i < 0 || j < 0 || i >= m || j >= n || mark[i][j] == 1 {
		return
	}

	if grid[i][j] == '0' {
		return
	}
	mark[i][j] = 1
	for d := 0; d < 4; d++ {
		search(grid, mark, i+dx[d], j+dy[d])
	}
}
```
