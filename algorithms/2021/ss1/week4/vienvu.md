# 1. Easy: determine-color-of-a-chessboard-square
https://leetcode.com/problems/determine-color-of-a-chessboard-square/


Submission Details
```
203 / 203 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 1.9 MB
```

Implementation:
```go
func squareIsWhite(coordinates string) bool {
	n, m := coordinates[0], coordinates[1]

	return  n % 2 != m % 2
}
```

# 2. Hard: n-queens
https://leetcode.com/problems/n-queens/
Submission Details
```
9 / 9 test cases passed.
Status: Accepted
Runtime: 8 ms
Memory Usage: 3.6 MB
```

Implementation:
```go
func solveNQueens(n int) [][]string {
	board := make([][]int, n)
	for i := 0; i < n; i++ {
		board[i] = make([]int, n)
	}
	result := make([][]string, 0)
	NQueen(board, 0, n, &result)
	return  result
}

func NQueen(board [][]int, row int, n int, result *[][]string) bool  {
	if row == n {
		solution := make([]string, 0)
		for i := 0; i < n; i++ {
			a := ""
			for j :=0; j < n; j++ {
				if board[i][j] == 1 {
					a += "Q"
				} else {
					a += "."
				}
			}
			solution = append(solution, a)
		}
		*result = append(*result, solution)
        
		return  true
	}
    
	for j := 0; j < n; j++ {
		if check(board, row, j, n) {
			board[row][j] = 1
			NQueen(board, row + 1, n, result)
			board[row][j] = 0
		}
	}

	return false
}

func check(board [][]int, row int, column int, n int) bool {
	for i := 0; i < row; i++ {
		if board[i][column] == 1 {
			return  false
		}
	}
	i := row
	j := column
	for i >= 0 && j >= 0 {
		if board[i][j] == 1 {
			return false
		}
		i -= 1
		j -= 1
	}
	i = row
	j = column

	for i >= 0 && j < n {
		if board[i][j] == 1 {
			return  false
		}
		i -= 1
		j += 1
	}
	return  true
}
```