Problem 1:

https://leetcode.com/problems/power-of-four

 Troll solution
  - Step 1: Run following code to get the condition:
```go
package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	var conditionBuilder strings.Builder
	checking := 4
	power := 0
	for true {
		result := math.Pow(float64(checking), float64(power))
		resultAsInt := int32(result)
		if resultAsInt < 0 { // If it's over signed int 32bit, it will be < 0
			break
		}
		conditionBuilder.WriteString(fmt.Sprintf("num == %d || ", resultAsInt))
		power = power + 1
		
	}
	fmt.Println(conditionBuilder.String())
  // num == 1 || num == 4 || num == 16 || num == 64 || num == 256 || num == 1024 || num == 4096 || num == 16384 || num == 65536 || num == 262144 || num == 1048576 || num == 4194304 || num == 16777216 || num == 67108864 || num == 268435456 || num == 1073741824 || 
}

```

 - Step 2: Run condition in leetcode
```
func isPowerOfFour(num int) bool {
    switch num {
case 1: return true
case 4: return true
case 16: return true
case 64: return true
case 256: return true
case 1024: return true
case 4096: return true
case 16384: return true
case 65536: return true
case 262144: return true
case 1048576: return true
case 4194304: return true
case 16777216: return true
case 67108864: return true
case 268435456: return true
case 1073741824: return true
    }
    return false
}
```

Problem 2:

https://leetcode.com/problems/number-of-islands

```go
func numIslands(grid [][]byte) int {
    if len(grid) == 0 {
		return 0
	}

	var numIslands int
    rows, cols := len(grid), len(grid[0])
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if grid[i][j] == 'x' {
				continue
			}

			if grid[i][j] == '1' {
				discoverIsland(grid, rows, cols, i, j)
				numIslands++
			} else {
				grid[i][j] = 'x'
			}
		}
	}

	return numIslands
}

func discoverIsland(g [][]byte, h, w, x, y int) {
    if (x < 0 || y < 0 || x >= h || y >= w) ||
    (g[x][y] == 'x' || g[x][y] == '0' ){
		return
	}

	g[x][y] = 'x'

	discoverIsland(g, h, w, x+1, y)
	discoverIsland(g, h, w, x, y+1)
	discoverIsland(g, h, w, x-1, y)
	discoverIsland(g, h, w, x, y-1)
}
```

Problem 3:

https://leetcode.com/problems/zuma-game

```go

func remove(s string) string {
	for i := 1; i < len(s); i++ {
		if s[i] != s[i-1] {
			continue
		}
		j := i + 1
		for s[j] == s[i] {
			j++
		}
		if j-i > 1 {
			return remove(s[0:i-1] + s[j:])
		}
	}
	return s
}

func dfs(board string, h, min []int, steps int) {
	if board == "P" && steps < min[0] {
		min[0] = steps
		return
	}

	if steps >= min[0] {
		return
	}

	for i := 0; i < len(board)-1; i++ {
		if i > 0 && board[i] == board[i-1] {
			continue
		}

		if board[i] == board[i+1] && h[board[i]-'A'] > 0 {
			newBoard := remove(board[0:i] + board[i+2:])
			h[board[i]-'A']--
			dfs(newBoard, h, min, steps+1)
			h[board[i]-'A']++

		} else if board[i] != board[i+1] && h[board[i]-'A'] > 1 {
			newBoard := remove(board[0:i] + board[i+1:])
			h[board[i]-'A']--
			h[board[i]-'A']--
			dfs(newBoard, h, min, steps+2)
			h[board[i]-'A']++
			h[board[i]-'A']++

		}

	}
}

func findMinStep(board string, hand string) int {
	min := []int{math.MaxInt32}
	h := make([]int, 26, 26)
	for _, b := range hand {
		h[b-rune('A')]++
	}

	dfs(board+"P", h, min, 0)
	if min[0] == math.MaxInt32 {
		return -1
	}
	return min[0]
}
```
