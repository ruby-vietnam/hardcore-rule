# Week 3

## Problem 1
https://leetcode.com/problems/min-stack/

Implement a stack with `push`, `pop`, `top` operations in constant time O(1) seems easy, we can use underlying data such as an list with amortized cost is O(1) or
sacrified little space (for pointers) by using linked list.

However, `getMin` operation is not so easy at first, there are several approaches, but they does not work well:
- Use a variable to refer to smallest value so far, this way, `getMin` is O(1) but it's not correct when this min value is popped out of stack, we need to update the variable with time consuming operation.
- Use a min heap, but time complexity is O(logn)
- Use a stack to store smallest value so far, only push into min stack when there is new min value, every value that is popped out of main stack that equal to min stack, value on top of min stack will be popped out as well. This methos will work only there is no duplicate items.

Based on the third idea, we expand further by always push smallest value so far to min stack, when main stack pops its item, min stack will pop its item too.

We can think of it by mapping a value in main stack with a value in min stack correspondingly.

```python
class MinStack:
    def __init__(self):
        self.stack = []
        self.min = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if len(self.min) == 0 or self.min[-1] > val:
            self.min.append(val)
        else:
            self.min.append(self.min[-1])

    def pop(self) -> None:
        self.stack.pop()
        self.min.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min[-1]
```
```

31 / 31 test cases passed.
Status: Accepted
Runtime: 56 ms
Memory Usage: 18 MB
```
Since number of values in main stack and min stack is equal, we can merge two stack into single stack, when each item is a pair of real value and its min value.

```python
class MinStack:
    def __init__(self):
        # stack contains a tuple of pair <val,min>
        self.stack = []

    def push(self, val: int) -> None:
        if len(self.stack) == 0 or self.stack[-1][1] > val:
            self.stack.append((val, val))
        else:
            self.stack.append((val, self.stack[-1][1]))

    def pop(self) -> None:
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.stack[-1][1]
```
## Problem 2
https://leetcode.com/problems/number-of-islands/

The main question when trying to solve this problem is that how we can correctly count island without mistakenly count previous island?

The answer is expanding any island we have seen so far, so when we encounter any slot `grid[i][j]` that is a land and belongs to an island, we increase the count 
and try to expand that island to its maximum area so when we see any new land `grid[i][j]`, if this land is not discovered so far (not belong to any island we have counted),
we know that this is a new island.

```python
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        island = 0
        discovered = [[False for _ in range(n)] for _ in range(m)]
        
        def expand(i, j):
            if discovered[i][j]:
                return
            # mark this slot as discovered
            discovered[i][j] = True
            # look surrounding slots to expand further
            if i - 1 >= 0 and grid[i-1][j] == '1':
                expand(i-1, j)
            if j - 1 >= 0 and grid[i][j-1] == '1':
                expand(i, j-1)
            if i + 1 < m and grid[i+1][j] == '1':
                expand(i+1, j)
            if j + 1 < n and grid[i][j+1] == '1':
                expand(i, j+1)
            
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1' and not discovered[i][j]:
                    # there is a new island
                    island += 1
                    expand(i, j)
        return island
```
```
48 / 48 test cases passed.
Status: Accepted
Runtime: 124 ms
Memory Usage: 15.6 MB
```
Since we don't need to keep original `grid` data, we can reduce space complexity by using `grid` itself as a discovery map.

```python
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        island = 0
        
        # look for 4 direction left, up, right, down to expand the island
        def expand(i, j):
            if grid[i][j] == -1:
                return
            # mark this slot as discovered
            grid[i][j] = -1
            # look surrounding slots to expand further
            if i - 1 >= 0 and grid[i-1][j] == '1':
                expand(i-1, j)
            if j - 1 >= 0 and grid[i][j-1] == '1':
                expand(i, j-1)
            if i + 1 < m and grid[i+1][j] == '1':
                expand(i+1, j)
            if j + 1 < n and grid[i][j+1] == '1':
                expand(i, j+1)
            
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    # there is a new island, increase counting and 
                    # try to expand it as much as possible
                    island += 1
                    expand(i, j)
        return island
```

Time complexity: O(mn), it's tempting to say that is O(mn*mn) because inside the two loops, we have `expand` method that might go through all slots `i, j` in the map,
but it's actually an armotized cost, so total time complexity for `expand` is O(mn) only, which is O(1) as an average time for single loop.

Space complexity: O(1), but we might have O(mn) for stack in `expand` recursive method.
