## problem 1

```
func findShortestSubArray(nums []int) int {
   mapIndex := map[int]int{} // number and its first index
	mapFreq := map[int]int{}
	degree := 0
	minLength := len(nums)
	for i, num := range nums {
		if _, exists := mapFreq[num]; exists {
			mapFreq[num]++
			if mapFreq[num] > degree {
				degree = mapFreq[num]
				minLength = i - mapIndex[num] + 1
			}
            if mapFreq[num] == degree {
				if minLength > i-mapIndex[num] {
					minLength = i - mapIndex[num] + 1
				}
			}

		} else {
			mapIndex[num] = i
			mapFreq[num] = 1
		}
	}


	if degree == 0 {
		return 1
	}


	return minLength

}
```

## problem 2

```

func updateMatrix(matrix [][]int) [][]int {
	m := len(matrix) // m rows
	n := 0           // n column

	// init output with -1
	output := make([][]int, len(matrix))
	for i, row := range matrix {
		output[i] = make([]int, len(row))
		for j := range output[i] {
			output[i][j] = -1
		}
		n = len(row)
	}

	type coordinate struct {
		x int
		y int
	}

	queue := []coordinate{}
	// init queue, start from cell = 0
	for i, row := range matrix {
		for j, cell := range row {
			if cell == 0 {
				queue = append(queue, coordinate{
					x: i,
					y: j,
				})
			}
		}
	}

	directions := [][]int{
		[]int{-1, 0}, // Up
		[]int{1, 0},  // Down
		[]int{0, -1}, // Left
		[]int{0, 1},  // Right
	}

	// loop through queue
	for len(queue) > 0 {
		// dequeue
		cor := queue[0]
		queue = queue[1:]

		minValue := m * n
		if matrix[cor.x][cor.y] == 0 {
			minValue = 0
		}

		fmt.Println(m, n)

		// check 4 directions
		for _, direction := range directions {
			newX := cor.x + direction[0]
			newY := cor.y + direction[1]
			// Check valid cell
			if newX >= 0 && newX < m && newY >= 0 && newY < n {
				// visited
				if output[newX][newY] != -1 {
					if minValue > output[newX][newY]+1 {
						minValue = output[newX][newY] + 1
					}
				} else {
					// Not visited then enqueue
					// Enqueue
					queue = append(queue, coordinate{
						x: newX,
						y: newY,
					})

				}
			}
		}

		// Update output
		output[cor.x][cor.y] = minValue
	}

	return output
}
```

## problem 3

```
func rotate(matrix [][]int)  {
  	n := len(matrix)
	for k := 0; k < n/2; k++ {
		for i := k; i < n-k-1; i++ {
			matrix[k][i], matrix[i][n-k-1] = matrix[i][n-k-1], matrix[k][i]
			matrix[k][i], matrix[n-i-1][k] = matrix[n-i-1][k], matrix[k][i]
			matrix[n-i-1][k], matrix[n-k-1][n-i-1] = matrix[n-k-1][n-i-1], matrix[n-i-1][k]
		}
	}
}
```
