### Problem 3

https://leetcode.com/contest/weekly-contest-70/problems/swim-in-rising-water/

```golang
var deltaX = []int{-1, 0, 1, 0}
var deltaY = []int{0, 1, 0, -1}

func swimInWater(grid [][]int) int {
	queue := [][]int{[]int{0, 0}}
	flag := make([][]bool, len(grid))
	distances := make([][]int, len(grid))

	for i := 0; i < len(grid); i++ {
		distances[i] = make([]int, len(grid))
		flag[i] = make([]bool, len(grid))
		for j := 0; j < len(grid); j++ {
			distances[i][j] = len(grid) * len(grid)
			flag[i][j] = false
		}
	}
	distances[0][0] = grid[0][0]
	for {
		if len(queue) == 0 {
			break
		}
		x := queue[0][0]
		y := queue[0][1]
		flag[x][y] = false
		queue = queue[1:]
		for dir := 0; dir < 4; dir++ {
			nextX := x + deltaX[dir]
			nextY := y + deltaY[dir]
			if nextX >= 0 && nextX < len(grid) && nextY >= 0 && nextY < len(grid) {
				d := max(distances[x][y], grid[nextX][nextY])
				if distances[nextX][nextY] > d {
					distances[nextX][nextY] = d
					fmt.Println("At point", nextX, nextY)
					fmt.Println("Update", d)
					if !flag[nextX][nextY] {
						queue = append(queue, []int{nextX, nextY})
						flag[nextX][nextY] = true
					}
				}
			}
		}
	}
	return distances[len(grid)-1][len(grid)-1]
}

func max(x int, y int) int {
	if x > y {
		return x
	}
	return y
}
```
