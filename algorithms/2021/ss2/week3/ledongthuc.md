# 1. Min Stack

https://leetcode.com/problems/min-stack

## 1.1. Summary

Building stack with two solutions:
 - Array
 - Linked list

## 1.2. Array

 -  Stack stores data in an array, internally.
 - An array item contains latest value and mininum value from starting until that latest value
 - Push = append array with 
	 - pushed value
	 - mininum value between pushed value and last minumum value
 - Pop = Remove latest item
 - Top = return latest item's value
 - Get min = return latest item's miniumum value

```go
type StackItem struct {
    Value int
    MinItemInThisTime int
}

type MinStack struct {
    InternalStack []StackItem
}

func Constructor() MinStack {
    return MinStack{InternalStack: make([]StackItem,0,0)}
}

func (this *MinStack) Push(x int)  {
    if len(this.InternalStack) == 0 {
        this.InternalStack = append(this.InternalStack, StackItem{ Value: x, MinItemInThisTime: x })
    } else {
        this.InternalStack = append(this.InternalStack, StackItem{ Value: x, MinItemInThisTime: min(this.GetMin(), x) })
    }
}

func (this *MinStack) Pop()  {
    this.InternalStack = this.InternalStack[:len(this.InternalStack) - 1]
}

func (this *MinStack) Top() int {
	return this.InternalStack[len(this.InternalStack) - 1].Value
}


func (this *MinStack) GetMin() int {
    return this.InternalStack[len(this.InternalStack) - 1].MinItemInThisTime
}

func min(v1, v2 int) int{
    if v1 > v2 {
        return v2
    }
    return v1
}
```

## 1.3. Linked list

 -  Stack stores data in a linked list, internally.
 - Stack keeps pointer to latest item of linked list. 
 - Linked list item refers to previous item.
 - An linked list item keeps latest value and mininum value from starting until that latest value
 - Push = Add new item to linked list. Stack keep new linked list item
 - Pop = Remove latest item. Stack keep previous linked list item.
 - Top = return latest item's value
 - Get min = latest last item's miniumum value

```go
type LinkedListItem struct {
    value int
    minValue int
    previous *LinkedListItem
}

type MinStack struct {
    latest *LinkedListItem
}

func Constructor() MinStack {
    return MinStack{}
}


func (this *MinStack) Push(val int)  {
    if this.latest == nil {
        this.latest = &LinkedListItem{value: val, minValue: val}
        return
    }
    
    this.latest = &LinkedListItem{
        value: val,
        minValue: min(this.latest.minValue, val),
        previous: this.latest,
    }
}

func (this *MinStack) Pop()  {
    fmt.Println("")
    this.latest = this.latest.previous
}

func (this *MinStack) Top() int {
    return this.latest.value
}


func (this *MinStack) GetMin() int {
    return this.latest.minValue
}

func min(v1, v2 int) int{
    if v1 > v2 {
        return v2
    }
    return v1
}
```


# 2. Number of Islands

https://leetcode.com/problems/number-of-islands

## 2.1. Summary

 - Start loop all cells of grid.
 - Found a water cell, skip.
 - Found a land cell:
	 - Number of islands ++
	 - Mark this cell is checked (we don't need to recheck again).
	 - Discover 4 directions (up/down/right/left) and continue to mark if their are land.
 - Found a checked/marked cell, skip.
 - Finally, we have total number of islands.

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
