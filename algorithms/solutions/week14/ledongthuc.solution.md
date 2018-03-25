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
