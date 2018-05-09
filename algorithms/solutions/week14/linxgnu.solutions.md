# Problem 1

```go
func isPowerOfFour(num int) bool {
    return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0x55555555) == num)
}
```

# Problem 2

```go
var directions = [][]int{
	[]int{0, 1},
	[]int{0, -1},
	[]int{1, 0},
	[]int{-1, 0},
}

func numIslands(grid [][]byte) int {
	if grid == nil || len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}

	m, n := len(grid), len(grid[0])
	flag, queue := make([][]bool, m), make([][]int, m*n)
	for i := range grid {
		flag[i] = make([]bool, n)
	}

	result := 0
	for i := range grid {
		for j := range grid[i] {
			if !flag[i][j] {
				if grid[i][j] == 49 {
					result++
				}

				BFS(m, n, i, j, flag, queue, grid, grid[i][j])
			}
		}
	}

	return result
}

func BFS(m, n, i, j int, flag [][]bool, queue [][]int, grid [][]byte, val byte) {
	if queue[0] == nil {
		queue[0] = []int{i, j}
	} else {
		queue[0][0], queue[0][1] = i, j
	}
	flag[i][j] = true

	s, e, old, index, x, y, x1, y1 := 0, 0, 0, 0, 0, 0, 0, 0
	for {
		for old, index = e, s; index <= e; index++ {
			y, x = queue[index][0], queue[index][1]
			for _, d := range directions {
				if y1, x1 = y+d[0], x+d[1]; y1 >= 0 && y1 < m && x1 >= 0 && x1 < n && !flag[y1][x1] && grid[y1][x1] == val {
					flag[y1][x1] = true
					e++
					if queue[e] == nil {
						queue[e] = []int{y1, x1}
					} else {
						queue[e][0], queue[e][1] = y1, x1
					}
				}
			}
		}

		if e == old {
			return
		}
		s = old + 1
	}
}
```
