# Easy: Min Stack

https://leetcode.com/problems/min-stack/

### Code (Go)

```go
type MinStack struct {
	Mins  []int
	Stack []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{}
}

func (this *MinStack) Push(val int) {
	if len(this.Mins) == 0 || val <= this.GetMin() {
		this.Mins = append(this.Mins, val)
	}
	this.Stack = append(this.Stack, val)
}

func (this *MinStack) Pop() {
	if this.Top() == this.GetMin() {
		this.Mins = this.Mins[:len(this.Mins)-1]
	}
	this.Stack = this.Stack[:len(this.Stack)-1]
}

func (this *MinStack) Top() int {
	return this.Stack[len(this.Stack)-1]
}

func (this *MinStack) GetMin() int {
	return this.Mins[len(this.Mins)-1]
}
```

### Submission Detail

```
31 / 31 test cases passed.
Status: Accepted
Runtime: 20 ms
Memory Usage: 8.5 MB
```

# Medium: Number of Islands

https://leetcode.com/problems/number-of-islands/

### Code (Go)

```go
func numIslands(grid [][]byte) int {
	if len(grid) == 0 {
		return 0
	}
	islands := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] == '1' {
				dfs(grid, i, j)
				islands += 1
			}
		}
	}
	return islands
}

func dfs(grid [][]byte, i int, j int) {
	if i < 0 || i >= len(grid) || j < 0 || j >= len(grid[i]) || grid[i][j] == '0' {
		return
	}
	grid[i][j] = '0'
	dfs(grid, i+1, j)
	dfs(grid, i-1, j)
	dfs(grid, i, j+1)
	dfs(grid, i, j-1)
}
```

### Submission Detail

```
48 / 48 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.8 MB
```
