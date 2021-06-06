# 155. Min Stack

### Approach - Stack

We use a `Stack` to keep pushed number (`nums`) and the minimum values (`mins`) as well.
When push a new number, we will push this num into `nums` and check it will the current minimun value.
- If this num is less than or equal to the top value of `mins` stack, we will push it into `mins`.
- If not we do nothing.

There is a special case, that the `mins` stack is empty, we will do not check, just push it.

### Submission

```
package dev.namtx.leetcode.minstack;

import java.util.ArrayList;

public class MinStack {


    /**
     * initialize your data structure here.
     */
    MyStack mins;
    MyStack nums;

    public MinStack() {
        mins = new MyStack();
        nums = new MyStack();
    }

    public void push(int val) {
        nums.push(val);

        if (mins.size() == 0 || val <= mins.peek()) {
            mins.push(val);
        }
    }

    public void pop() {
        int val = nums.peek();
        nums.pop();
        if (val == mins.peek()) {
            mins.pop();
        }
    }

    public int top() {
        return nums.peek();
    }

    public int getMin() {
        return mins.peek();
    }

    class MyStack {
        ArrayList<Integer> arr;

        public MyStack() {
            arr = new ArrayList<>();
        }

        public void push(int val) {
            arr.add(val);
        }

        public int peek() {
            return arr.get(arr.size() - 1);
        }

        public void pop() {
            arr.remove(arr.size() - 1);
        }

        public int size() {
            return arr.size();
        }
    }
}

```
### Submission detail

31 / 31 test cases passed.
Runtime: 8 ms
Memory Usage: 45.8 MB

### Analyzing

- Time complexity: O(1)
- Space complexity: O(n)

# 200. Number of Islands

### Approach - DFS

We use a `boolean[][] mark` - to keep track the traversed grid, for each grid at (i, j) we will mark it as already traversed and find around grid which in the same island by DFS.


### Submission

```java
import java.util.Arrays;

public class Solution {
    public int numIslands(char[][] grid) {
        boolean[][] mark = new boolean[grid.length][grid[0].length];
        for (boolean[] r : mark) {
            Arrays.fill(r, false);
        }

        int count = 0;

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (mark[i][j]) {
                    continue;
                }

                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, mark, grid);
                }
            }
        }

        return count;
    }

    public void dfs(int i, int j, boolean[][] mark, char[][] grid) {
        mark[i][j] = true;
        // top
        if (i > 0 && !mark[i - 1][j] && grid[i - 1][j] == '1') {
            dfs(i - 1, j, mark, grid);
        }
        //bottom
        if (i < grid.length - 1 && !mark[i + 1][j] && grid[i + 1][j] == '1') {
            dfs(i + 1, j, mark, grid);
        }
        // left
        if (j > 0 && !mark[i][j - 1] && grid[i][j - 1] == '1') {
            dfs(i, j - 1, mark, grid);
        }
        // right
        if (j < grid[0].length - 1 && !mark[i][j + 1] && grid[i][j + 1] == '1') {
            dfs(i, j + 1, mark, grid);
        }
    }
}

```

### Submission detail

48 / 48 test cases passed.
Runtime: 2 ms
Memory Usage: 44.6 MB

### Analyzing

- Space complexity: O(mn)
- Time complexity O(mn)
