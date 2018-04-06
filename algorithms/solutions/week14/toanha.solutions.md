## Problem 2

Tại 1 điểm ta sẽ duyệt theo 4 chiều từ nó đi ra (trái, phải, trên, dưới) nếu như gặp biển thì dừng và đánh dấu lại những điểm đã từng duyệt qua

```golang
func search(grid [][]byte, i, j int) {
  if i < 0 || j < 0 || i >= len(grid) || j >= len(grid[0]) || grid[i][j] != '1' {
    return
  }

  grid[i][j] = '-'
  search(grid, i-1, j)
  search(grid, i+1, j)
  search(grid, i, j-1)
  search(grid, i, j+1)
}

func numIslands(grid [][]byte) int {
  var count int

  for i := 0; i < len(grid); i++ {
    for j := 0; j < len(grid[0]); j++ {
      if grid[i][j] == '1' {
        search(grid, i, j)
        count++
      }
    }
  }

  return count
}
```
