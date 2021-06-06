# Easy: Min Stack

https://leetcode.com/problems/min-stack/

### Approach

Design a stack that supports push, pop, and top elements is simple, but design a stack that supports retrieving the minimum element in *constant time* can be tricky. The first solution came to mind is to use a variable to store the min element in the stack, but when the stack pops that element out you will lose track of the min element in the stack.

Whenever we push an element to the stack, we need to know whether that element is the min element in the stack so far. If it is, we will store it in another `min` stack. This way when we pop an element from the main stack and if that element is also the same with the top element in the `min` stack, we will pop that element out as well from the `min` stack, and now the min value left in the stack will be the top element in the `min` stack.

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

Space complexity: O(n).

### Submission Detail

```
31 / 31 test cases passed.
Status: Accepted
Runtime: 20 ms
Memory Usage: 8.5 MB
```

# Medium: Number of Islands

https://leetcode.com/problems/number-of-islands/

### Approach

Traverse through every cell in the map:
- if it is water, skip
- if it is a land, it may be a part of an island, so use DFS to mark that cell and all adjacent cells, and increase the number of islands to 1

Strategy to mark a cell:
1. Check if `grid[i][j]` == 1, then change its value to 0 (so if we visit this cell again, we will skip it).
2. Do the same thing for adjacent cells, but if they are water then skip.

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

Time complexity: O(m * n), space complexity: O(m * n).

### Submission Detail

```
48 / 48 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.8 MB
```
