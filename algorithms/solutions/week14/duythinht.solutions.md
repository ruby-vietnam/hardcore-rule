### Problem 2

https://leetcode.com/problems/number-of-islands/description/

Leetcode runtime Error detected :troll:

```
void visit(char** grid, int x, int y, int w, int h) {
    // return if node is invalid
    if (x < 0 || x > h -1 || y < 0 || y > w - 1) {
      return;
    }

    // if reach the water or node, which is visited, return.
    if (grid[x][y] == '0') {
        return;
    }

    grid[x][y] = '0';
    visit(grid, x, y - 1, w, h);
    visit(grid, x, y + 1, w, h);
    visit(grid, x - 1, y, w, h);
    visit(grid, x + 1, y, w, h);
}
int numIslands(char** grid, int height, int width) {
    int count = 0;
    for (int i = 0; i < width * height; i++) {
        int x = i / width;
        int y = i % width;
        if (grid[x][y] == '1') {
            count++;
            visit(grid, x, y, width, height);
        }
    }
    return count;
}

```
