## Problem 1 - [Plus One](https://leetcode.com/problems/plus-one/description/)

```go
func plusOne(digits []int) []int {
    n := len(digits)
    if n <= 0 {
        return digits
    }
    
    var tmp int
    carry := 1
    for i := n - 1; i >= 0; i-- {
        if tmp = digits[i] + carry; tmp > 9 {
            digits[i], carry = tmp - 10, 1
        } else {
            digits[i], carry = tmp, 0
        }
    }
    if carry == 0 {
        return digits
    }
    
    return append([]int{1}, digits...)
}
```

## Problem 2 - [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/description/)

```go
var MaxInt32 int64 = 1<<31 - 1
var MinInt32 int64 = 1 << 31

func myAtoi(str string) int {
    startAt, isMinus := -1, false
    for i := range str {
        if str[i] == '-' {
            startAt, isMinus = i + 1, true
            break
        } else if str[i] == '+' {
            startAt = i + 1
            break
        } else if str[i] >= '0' && str[i] <= '9' {
            startAt = i
            break
        } else if str[i] != ' ' {
            return 0
        }
    }
    
    if startAt < 0 {
        return 0
    }
    
    var result int64
    for i := startAt; i < len(str); i++ {
        if str[i] < '0' || str[i] > '9' {
            break
        }
        
        result = result * 10 + int64(str[i] - '0')
        if isMinus {
            if result >= MinInt32 {
                return int(-MinInt32)
            }
        } else if result >= MaxInt32 {
            return int(MaxInt32)
        }
    }
    
    if isMinus {
        return int(-result)
    }
    
    return int(result)
}
```

## Problem 3 - [Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/)

```go
var directions [][]int = [][]int{
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
}

type Node struct {
    degree byte
    index int
    ln   int // longest increasing path to this node
    row int
    col int
}

type HeapNode []*Node

func (h HeapNode) Len() int { return len(h) }

func (h HeapNode) Less(i, j int) bool {
	return h[i].degree < h[j].degree
}

func (h HeapNode) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
	h[i].index = i
	h[j].index = j
}

func (h *HeapNode) Push(x interface{}) {
	n := len(*h)
	item := x.(*Node)
	item.index = n
	*h = append(*h, item)
}

func (h *HeapNode) Pop() interface{} {
	old := *h
	n := len(old)
	item := old[n-1]
	item.index = -1 // for safety
	*h = old[0 : n-1]
	return item
}

func longestIncreasingPath(matrix [][]int) int {
    // input validate
    m := len(matrix)
    if m <= 0 {
        return 0
    }
    
    n := len(matrix[0])
    if n <= 0 {
        return 0
    }
    
    // iterator and local variables
    var i, j, ii, jj, ln int
    var tmp, node *Node
    
    // heap and dp
    f, h := make([][]*Node, m), make(HeapNode, 0, m * n)
    for i := range f {
        f[i] = make([]*Node, n)
    }
    for i = 0; i < m; i++ {
        for j = 0; j < n; j++ {
            tmp = &Node{
                degree: getDegree(matrix, m, n, i, j),
                ln : 1,
                row : i,
                col : j,
            }
            heap.Push(&h, tmp)
            f[i][j] = tmp
        }
    }
    
    max := 1
    for len(h) > 0 {
        tmp = heap.Pop(&h).(*Node)
        
        i, j, ln = tmp.row, tmp.col, tmp.ln + 1
        if ln - 1 > max {
            max = ln - 1
        }
        
        for _, dir := range directions {
            ii, jj = i + dir[0], j + dir[1]
            if ii >= 0 && ii < m && jj >= 0 && jj < n && matrix[i][j] < matrix[ii][jj] {
                node = f[ii][jj]
                
                node.degree--
                if node.ln < ln {
                    node.ln = ln
                }
                
                heap.Fix(&h, node.index)
            }
        }
    }
    
    return max
}

func getDegree(matrix [][]int, m, n, i, j int) (deg byte) {
    var ii, jj int
    for _, dir := range directions {
        ii, jj = i + dir[0], j + dir[1]
        if ii >= 0 && ii < m && jj >= 0 && jj < n && matrix[i][j] > matrix[ii][jj] {
            deg++
        }
    }
    return
}
```