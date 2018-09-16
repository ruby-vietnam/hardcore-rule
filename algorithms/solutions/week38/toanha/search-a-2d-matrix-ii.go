package main

func searchMatrix(matrix [][]int, target int) bool {
	row := 0
	col := len(matrix[0]) - 1

	for col >= 0 && row <= len(matrix[0])-1 {
		if matrix[row][col] == target {
			return true
		} else if matrix[row][col] > target {
			col--
		} else if matrix[row][col] < target {
			row++
		}
	}

	return false
}

// func main() {
// 	fmt.Println(searchMatrix([][]int{
// 		[]int{1, 4, 7, 11, 15},
// 		[]int{2, 5, 8, 12, 19},
// 		[]int{3, 6, 9, 16, 22},
// 		[]int{10, 13, 14, 17, 24},
// 		[]int{18, 21, 23, 26, 30}}, 5))
// }
