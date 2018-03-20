## Problem 1

```go
func isPowerOfFour(n int) bool {
   return n == 1 || n == 4 || n == 16 || n == 64 || n == 256 || n == 1024 || n == 4096 || n == 16384 || n == 65536 || n == 262144 || n == 1048576 || n == 4194304 || n == 16777216 || n == 67108864 || n == 268435456 || n == 1073741824 || n == 4294967296
}
```

## Problem 2

```go
func visit(grid [][]byte, isVisited [][]bool, i, j, width, height int) {
    if isVisited[i][j] {
        return
    }

    isVisited[i][j] = true

    // go right
	if j < width - 1 && grid[i][j + 1] == '1' {
		visit(grid, isVisited, i, j + 1, width, height)
    }
    
    // go left
	if j > 0 && grid[i][j - 1] == '1' {
		visit(grid, isVisited, i, j - 1, width, height)
    }
    
    // go down
	if i < height - 1 && grid[i + 1][j] == '1' {
		visit(grid, isVisited, i + 1, j, width, height)
    }
    
    // go up
	if i > 0 && grid[i - 1][j] == '1' {
		visit(grid, isVisited, i - 1, j, width, height)
	}
}

func numIslands(grid [][]byte) int {
    count := 0
    
    // get size of grid
	height := len(grid)
	width := 0
	if height > 0 {
		width = len(grid[0])
	}

    // make a visited array
    // XXX: does golang support better way to create 2D array?
	isVisited := make([][]bool, height)
	for i := range isVisited {
		isVisited[i] = make([]bool, width)
	}

	for i := 0; i < height; i++ {
		for j := 0; j < width; j++ {
			if isVisited[i][j] || grid[i][j] != '1' {
				continue
			}
			count = count + 1
			visit(grid, isVisited, i, j, width, height)	
		}
	}

	return count
}
```