# Problem 1: Move Zeroes

```
// O(n^2) solution
func moveZeroes(nums []int)  {
    if nums == nil {
        return
    }
    
    n := len(nums)
    if n <= 1 {
        return
    }
    
    var j int
    for i := n - 1; i >= 0; i-- {
        if nums[i] != 0 {
            continue
        }
        
        for j = i + 1; j < n && nums[j] != 0; j++ {
            nums[j], nums[j-1] = nums[j-1], nums[j]
        }
    }
}
```

```
// O(N)
func moveZeroes(nums []int)  {
    n := len(nums)
    if n <= 1 {
        return
    }
    
    lastZero := -1
    for i := range nums {
        if nums[i] == 0 {
            if lastZero == -1 {
                lastZero = i
            }
        } else if lastZero >= 0 {
            nums[i], nums[lastZero] = nums[lastZero], nums[i]
            lastZero++
        }
    }
}
```

# Problem 2: Ugly Number II

```
// O(N * Log N)
func nthUglyNumber(n int) int {
    if n == 1 {
        return 1
    }
    
    mark := make(map[int]struct{}, n)
    h := make(IntHeap, 1, n)
    h[0], mark[1] = 1, struct{}{}
    
    var top int
    var ok bool
    for i := 1; i <= n; i++ {
        if top = heap.Pop(&h).(int); i == n {
            return top
        }
        
        if _, ok = mark[top * 2]; !ok {
            mark[top * 2] = struct{}{}
            heap.Push(&h, top * 2)
        }
        
        if _, ok = mark[top * 3]; !ok {
            mark[top * 3] = struct{}{}
            heap.Push(&h, top * 3)
        }
        
        if _, ok = mark[top * 5]; !ok {
            mark[top * 5] = struct{}{}
            heap.Push(&h, top * 5)
        }
    }
    
    return 0
}

// An IntHeap is a min-heap of ints.
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
```

# Bonus: Sudoku Solver

```
func solveSudoku(board [][]byte)  {
    convertBoard(board)
    
    // solve sudoku
    rows := make([][]bool, 9)
    for i := range rows {
        rows[i] = make([]bool, 10)
    }
    
    cols := make([][]bool, 9)
    for i := range cols {
        cols[i] = make([]bool, 10)
    }
    
    area := make([][]bool, 9)
    for i := range area {
        area[i] = make([]bool, 10)
    }
    
    // 
    notFill := 0
    for i, v := range board {
        for j := range v {
            if v[j] == 0 {
                notFill++
            } else {
                rows[i][v[j]] = true
                cols[j][v[j]] = true
                area[getAreaIndex(i,j)][v[j]] = true
            }
        }
    }
    
    // 
    x, y := make([]int, notFill), make([]int, notFill)
    blankCount := 0
    for i, v := range board {
        for j := range v {
            if v[j] == 0 {
                x[blankCount], y[blankCount] = i, j
                blankCount++
            }
        }
    }
    
    //
    _solve(0, byte(notFill), board, x, y, rows, cols, area)
    
    // 
    convertBoard(board)
}

func _solve(current, limit byte, board [][]byte, x, y []int, rows, cols, area [][]bool) bool {
    if current >= limit {
        return true
    }
    
    i, j := x[current], y[current]
    k := getAreaIndex(i, j)
    
    var v byte
    for v = 1; v <= 9; v++ {
        if !rows[i][v] && !cols[j][v] && !area[k][v] {
            rows[i][v], cols[j][v], area[k][v] = true, true, true
            board[i][j] = v
            if _solve(current+1, limit, board, x, y, rows, cols, area) {
                return true
            }
            rows[i][v], cols[j][v], area[k][v] = false, false, false
        }
    }
    
    return false
}

func convertBoard(board [][]byte) [][]byte {
    for _, v := range board {
        for j := range v {
            if v[j] == 46 {
                v[j] = 0
            } else if v[j] >= 48 {
                v[j] -= 48
            } else if v[j] == 0 {
                v[j] = 46
            } else {
                v[j] += 48
            }
        }
    }

    return board
}

func getAreaIndex(i, j int) int {
    r, c := i / 3, j / 3
    return r * 3 + c
}
```
