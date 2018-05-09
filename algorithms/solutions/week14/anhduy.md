# 342

```c
bool isPowerOfFour(int num) {
  return ((num-1) & num) == 0 && (num-1) % 3 == 0;
}
```

# 200

```c
void dfs(char** grid, int** map, int gridRowSize, int gridColSize, int r, int c, int count) {
  int row = r;
  int col = c;
  map[row][col] = count;
  if(row - 1 >= 0 && grid[row - 1][col] == '1' && map[row - 1][col] == 0) {
    dfs(grid, map, gridRowSize, gridColSize, row - 1, col, count);
  }
  if (col - 1 >= 0 && grid[row][col - 1] == '1' && map[row][col - 1] == 0) {
    dfs(grid, map, gridRowSize, gridColSize, row, col - 1, count);
  }
  if (row + 1 < gridRowSize && grid[row + 1][col] == '1' && map[row + 1][col] == 0) {
    dfs(grid, map, gridRowSize, gridColSize, row + 1, col, count);
  }
  if (col + 1 < gridColSize && grid[row][col + 1] == '1' && map[row][col + 1] == 0) {
    dfs(grid, map, gridRowSize, gridColSize, row, col + 1, count);
  }
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
  int** map = malloc(sizeof(int*) * gridRowSize);
  int count = 0;

  for (int i = 0; i < gridRowSize; i++) {
    map[i] = malloc(sizeof(int) * gridColSize);
  }

  for (int i = 0; i < gridRowSize; i++) {
    for (int j = 0; j < gridColSize; j++) {
      map[i][j] = 0;
    }
  }

  for (int i = 0; i < gridRowSize; i++) {
    for (int j = 0; j < gridColSize; j++) {
      if (grid[i][j] == '1' && map[i][j] == 0) {
        count++;
        bfs(grid, map, gridRowSize, gridColSize, i, j, count);
      }
    }
  }

  return count;
}

```
