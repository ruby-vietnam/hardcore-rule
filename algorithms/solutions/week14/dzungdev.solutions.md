Problem2: https://leetcode.com/problems/number-of-islands/description/

We will use BFS to search from the node which is 1. We store the position of the node which is calculate by: curRow * colNum + colNum. 
Then each time the BFS travel to one node which is 1, we will go to neighbor node to check whether it is 1 or not. If we meet the neighbor node is 1
then we set it 0 and add the position of that cell to Queue to find neighbor of that node. We set the node = 1 to 0 because we only count the first 1 of that island 

E.g: 1 1 1 so in BFS it will be 1 0 0 then it is 1 island
     1 1 0                      0 0 0
     0 0 0                      0 0 0
     
Time Complexity is O(Rows x Cols) as in worse case we will need to loop all node of graph
Space complexity is O(min(Row, Col)) as in worse case when all node is 1, so the Queue has max element is Rows/Cols

```java
public int numIslands(char[][] grid) {
    if (grid == null || grid.length == 0) {
      return 0;
    }
    
    int rowNum = grid.length;
    int colNum = grid[0].length;
    
    int islandsNum = 0;
    
    for (int r = 0; r < rowNum; r++) {
      for(int c = 0; c < colNum; c++) {
        if (grid[r][c] == '1') {
          ++islandsNum;//when we find one 1, then increase number of islands with 1
          Queue<Integer> neighbors = new LinkedList<>();
          //This one is number of how many cells we moved from left to right to the cell before current cell
          //for example: if we have grid which have size is (4,5) so the cell we need to move to cell (1, 2) 
          // will be: 1 * 5 + 2 = 7
          neighbors.add(r * colNum + c);
          while (!neighbors.isEmpty()) {
            int posNum = neighbors.remove();
            int curRow = posNum / colNum;//This is curRow for neighbor island
            int curCol = posNum % colNum;//This is curCol for neighbor island
            
            if (curRow - 1 >= 0 && grid[curRow-1][curCol] == '1') {
              neighbors.add((curRow-1) * colNum + curCol);
            //because 2 islance next to will be consider is 1 island only, so we just count the first 1, for other 1 we set to 0
              grid[curRow-1][curCol] = '0';
            }
            
            if (curRow + 1 < rowNum && grid[curRow+1][curCol] == '1') {
              neighbors.add((curRow+1) * colNum + curCol);
            //because 2 islance next to will be consider is 1 island only, so we just count the first 1, for other 1 we set to 0
              grid[curRow+1][curCol] = '0';
            }
            
            if (curCol - 1 >= 0 && grid[curRow][curCol-1] == '1') {
              neighbors.add(curRow * colNum + curCol -1);
              grid[curRow][curCol-1] = '0';
            }
            
            if (curCol + 1 < colNum && grid[curRow][curCol+1] == '1') {
              neighbors.add(curRow * colNum + curCol +1);
              grid[curRow][curCol+1] = '0';
            }
            
          }
        }
      }
    }
    return islandsNum;
  }
```
     
