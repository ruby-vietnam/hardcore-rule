## Problem 1

Dễ thấy nếu 1 số là power of 4 thì sẽ là power of 2. Để kiểm tra 1 số là power of 2, ta có điều kiện `num > 0` và `num & num - 1 == 0`
Điều kiện `num & num - 1 == 0` được giải thích như sau: 
- Một số là power of 2 thì chỉ có duy nhất một bit `1`. Ví dụ như: xxxx1000
- Khi số này trừ đi 1, sẽ thành xxxx0111. Khi sử dụng phép `&` thì sẽ làm mất đi bit 1 duy nhất này và kết quả sẽ là xxxx0000
- Điều kiện `num & num - 1 == 0` thực chất làm mất đi low bit (bit 1 cuối cùng) của 1 số. Nếu nó là bit 1 duy nhất suy ra số đó là power of 2 và ngược lại
Điều kiện cuối cùng là `(num & 0x55555555) == num`. `0x55555555` là `4^0 | 4^1 | 4^2 | 4^3 ...`, cái này dễ không giải thích nữa :troll:

```go
func isPowerOfFour(num int) bool {
    return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0x55555555) == num)
}
``

## Problem 2
```go
func numIslands(grid [][]byte) int {
    if grid == nil || len(grid) == 0 || len(grid[0]) == 0 {
        return 0
    }
    
    result := 0
    
    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid[i]); j++ {
            if grid[i][j] == 1 {
                dfs(grid, i, j)
                result++
            }
        }
    }
    return result
}

func dfs(grid [][]byte, x int, y int) {
    if x < 0 || len(grid) <= x || y < 0 || len(grid[0]) <= y || grid[x][y] != 1 {
        return
    }
    
    grid[x][y] = 0
    dfs(grid, x + 1, y)
    dfs(grid, x - 1, y)
    dfs(grid, x, y + 1)
    dfs(grid, x, y - 1)
}
```
