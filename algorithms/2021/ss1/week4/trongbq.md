# Week 4

## Problem 1
https://leetcode.com/problems/determine-color-of-a-chessboard-square/

### Basic

We can see that there is huge repetition, for example, column a has even row is white and odd row is black, while column b is reversed, even row is black and odd row is white. This pattern is repeated for consequence columns.

By using a hashmap to recoding this rule, we can solve the proble quite easily.

**Analysis**

Time complexity: O(1)
Space complexity: O(1) - only a hashmap with 8 elements, but if we assume n is number of `coordinates[1]` then complexity now is O(n).

```python
class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        mem = {
            'a': 1,
            'b': 0,
            'c': 1,
            'd': 0,
            'e': 1,
            'f': 0,
            'g': 1,
            'h': 0
        }
        
        return int(coordinates[1]) % 2 != mem[coordinates[0]]
```
```
203 / 203 test cases passed.
Status: Accepted
Runtime: 24 ms
Memory Usage: 14.3 MB
```

### Convert column to number

To avoid using a hashmap, and still want to keep the rule above, we can convert column to number and use condition to return correct answers.

```python
class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        # convert column to number, start with 0
        col = ord(coordinates[0]) - ord('a')
        
        row = int(coordinates[1])
        if col % 2 == 0:
            return row % 2 != 1
        return row % 2 != 0
```
```
203 / 203 test cases passed.
Status: Accepted
Runtime: 32 ms
Memory Usage: 14.3 MB
```

This approach take a bit longer to run.

## Convert column to number version 2

Notice that if we convert column to number, start with 1, then if column + row is even then that slot is black, otherwise, it is white.

```python
class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        # convert column to number, start with 1
        col = ord(coordinates[0]) - ord('a') + 1
        
        row = int(coordinates[1])
        return (col + row) % 2 != 0
```
```
203 / 203 test cases passed.
Status: Accepted
Runtime: 32 ms
Memory Usage: 14.3 MB
```

Still take a bit longer time to run, so first approach seems to be better, verbose, but better.

## Problem 2
https://leetcode.com/problems/knight-dialer

### Brute Force

For each position, we have maximum 8 possible moves for the knight, so for each valid position on the keypad, we can try to go to 8 possible numbers.

Since initialy we place the knight on single number from 0 to 9, so all the numbers that is dialed from initial number are different ones.

Total number that can be dial is the sum of all possible moves, recursively.

**Analysis**

With `n` is number of steps, we have:

Time complexity is 12*8^n = O(8^n).

Space complexity is 12 for keypad, 8 for number of moves, and n for stack so O(n) overall.

```python
class Solution:
    def knightDialer(self, steps: int) -> int:
        # pad phone number, with `*` and `#` is denoted as -1
        pad = [[1,2,3],[4,5,6],[7,8,9],[-1,0,-1]]
        n = 4
        m = 3
        
        # collections of 8 possible moves
        moves = [
            lambda x, y: (x-2, y-1), 
            lambda x, y: (x-1, y-2),
            lambda x, y: (x+1, y-2),
            lambda x, y: (x+2, y-1),
            lambda x, y: (x-2, y+1),
            lambda x, y: (x-1, y+2),
            lambda x, y: (x+1, y+2),
            lambda x, y: (x+2, y+1),
        ]
        
        def go(move, s):
            # validate move
            if move[0] < 0 or move[0] >= n or move[1] < 0 or move[1] >= m:
                return 0
            # exclude invalid move for position of `*` and `#`
            if pad[move[0]][move[1]] == -1:
                return 0
            
            # if number of steps reaches limit, return 1 to count 1 possible way to dial phone number
            if s == steps:
                return 1
            
            # get sum of all possible moves
            t = 0
            for mv in moves:
                t += go(mv(move[0], move[1]), s+1)
            return t
                
        
        total = 0
        # initialy place the knight on each numeric cell
        for x in range(n):
            for y in range(m):
                total += go((x, y), 1)
        return total
```

### Memorization
We can see that if we move to a certain number on the keypad, we might already calculate recursively how many possible moves we can go from this number (how many numbers we can dial next).

Caching this calculation can save us so much time.

```python
class Solution:
    def knightDialer(self, steps: int) -> int:
        mod = pow(10, 9) + 7

        # pad phone number, with `*` and `#` is denoted as -1
        pad = [[1,2,3],[4,5,6],[7,8,9],[-1,0,-1]]
        n = 4
        m = 3

        # collections of 8 possible moves
        moves = [
            lambda x, y: (x-2, y-1), 
            lambda x, y: (x-1, y-2),
            lambda x, y: (x+1, y-2),
            lambda x, y: (x+2, y-1),
            lambda x, y: (x-2, y+1),
            lambda x, y: (x-1, y+2),
            lambda x, y: (x+1, y+2),
            lambda x, y: (x+2, y+1),
        ]

        def go(move, s):
            # validate move
            if move[0] < 0 or move[0] >= n or move[1] < 0 or move[1] >= m:
                return 0
            # exclude invalid move for position of `*` and `#`
            if pad[move[0]][move[1]] == -1:
                return 0

            # if number of steps reaches limit, return 1 to count 1 possible way to dial phone number
            if s == steps:
                return 1

            # we already went to this place, return from our excellent memory
            rs = steps - s # how many moves left
            if mem[pad[move[0]][move[1]]][rs] != -1:
                return mem[pad[move[0]][move[1]]][rs]

            # get sum of all possible moves
            t = 0
            for mv in moves:
                t += go(mv(move[0], move[1]), s+1)
            # let's save it for later use
            mem[pad[move[0]][move[1]]][rs] = t
            return t

        # mem is a 2D array with rows are phone numbers and columns are remaining moves
        mem = [[-1 for _ in range(steps)] for _ in range(10)]

        total = 0
        # initialy place the knight on each numeric cell
        for x in range(n):
            for y in range(m):
                total += go((x, y), 1)
        # int type in Python is unbound so no need to worry about overflow :D
        return total % mod
```
```
TLE at 4932 :(
```

### Challenge accepted

Even with memorization, we can not pass at 4932. Python is slow, but it's good, it forces us to continue seeking for optimization, never settle down, that's bright side of a problem.

Let's try to do bottom up, we can reduce time and space for recursive calls.

```python
class Solution:
    def knightDialer(self, jumps: int) -> int:
        mod = pow(10, 9) + 7

        # pad phone number, with `*` and `#` is denoted as -1
        pad = [[1,2,3],[4,5,6],[7,8,9],[-1,0,-1]]
        n = 4
        m = 3

        # collections of 8 possible moves
        moves = [
            lambda x, y: (x-2, y-1), 
            lambda x, y: (x-1, y-2),
            lambda x, y: (x+1, y-2),
            lambda x, y: (x+2, y-1),
            lambda x, y: (x-2, y+1),
            lambda x, y: (x-1, y+2),
            lambda x, y: (x+1, y+2),
            lambda x, y: (x+2, y+1),
        ]
        
        # mem is a 2D array with rows are phone numbers columns are remaining moves
        mem = [[0 for _ in range(jumps+1)] for _ in range(10)]
        # init for the base move
        for i in range(10):
            mem[i][1] = 1
            
        for s in range(2, jumps+1):
            for x in range(n):
                for y in range(m):
                    if pad[x][y] == -1:
                        continue
                    t = 0
                    for mv in moves:
                        # execute the move and check if the move is valid
                        xx, yy = mv(x, y)
                        if xx < 0 or xx >= n or yy < 0 or yy >= m:
                            continue
                        if pad[xx][yy] == -1:
                            continue
                        # valid move, add to the total
                        t += mem[pad[xx][yy]][s-1]
                    mem[pad[x][y]][s] = t

        total = 0
        # initialy place the knight on each numeric cell
        for x in range(n):
            for y in range(m):
                if pad[x][y] == -1:
                        continue
                total += mem[pad[x][y]][jumps]
        return total % mod
```
```

121 / 121 test cases passed.
Status: Accepted
Runtime: 7288 ms
Memory Usage: 33.7 MB
```

Accepted at last.

**Analysis**

Time complexity: O(n\*4\*3\*8) due to 4 for-loops, which is O(n).

Space complexity: O(n\*10) for the `mem`, or O(n).

### Improvement
Using keypad and possible moves are a great way for visualization, but we want a faster algorithm so we need to find a way to reduce running time.

Number of moves are limited due to range of numbers is limited on the keypad, so we can defined all possible moves beforehand.

```python
class Solution:
    def knightDialer(self, jumps: int) -> int:
        mod = pow(10, 9) + 7
        
        # init all possible moves
        moves = {
            0: [4, 6],
            1: [6, 8],
            2: [7, 9],
            3: [4, 8],
            4: [0, 3, 9],
            5: [],
            6: [0, 1, 7],
            7: [2, 6],
            8: [1, 3],
            9: [2, 4]
        }
        
        # mem is a 2D array with rows are phone numbers columns are number of moves
        mem = [[0 for _ in range(jumps+1)] for _ in range(10)]
        # init for the base move
        for i in range(10):
            mem[i][1] = 1
        
        for s in range(2, jumps+1):
            for num in range(10):
                for mv in moves[num]:
                    mem[num][s] += mem[mv][s-1]

        total = 0
				# initialy place the knight on each numeric cell
        for num in range(10):
            total += mem[num][jumps]

        return total % mod
```
```
121 / 121 test cases passed.
Status: Accepted
Runtime: 1508 ms
Memory Usage: 33.8 MB
```
As we can see, running time is greatly reduced, from 7288 ms to 1508 ms.

Can this algorithm be improved more?

### Space complexity improvement

Notice that we have `mem` is a 2D array with one dimention (column) is a list of moves, but we only refer to the move right before current move.

Let's reduce it to 1D array.

```python
class Solution:
    def knightDialer(self, jumps: int) -> int:
        mod = pow(10, 9) + 7
        
        # init all possible moves
        moves = {
            0: [4, 6],
            1: [6, 8],
            2: [7, 9],
            3: [4, 8],
            4: [0, 3, 9],
            5: [],
            6: [0, 1, 7],
            7: [2, 6],
            8: [1, 3],
            9: [2, 4]
        }
        
        # mem store result for current move
        mem = [1 for _ in range(10)]

        for s in range(2, jumps+1):
            temp = copy.deepcopy(mem)
            for num in range(10):
                mem[num] = sum([temp[mv] for mv in moves[num]]) 

        return sum(mem) % mod
```
```
121 / 121 test cases passed.
Status: Accepted
Runtime: 3384 ms
Memory Usage: 14.3 MB
```

Great, space complexity now is O(1), seems like Python needs some extra time on copying array so time complexity goes up a bit.
## Problem 3
https://leetcode.com/problems/n-queens

We have n queens need to be placed in n x n board. Start by placing a queen on first column and all row slots in this column, recursively move to the next column if previous placement is a valid, when placing n queens on the board, recoding the solutions.

The hard part is how to check if a placement is a valid one, based on the way we approach the puzzle, from left to right column, and top to bottom row, there are some observation to make this check easier:

- There are no two queens have same row or column: since we place a single queen on a single column `c` at row index `r`, we can be sure that if no queens in the `board[r][:c]`  then this condition is satisfied.
- Normally there are two diagonals, so 4 possible directions need to check for a single place `(r,c)`, but we approach from left to right, so two directions from the right are not needed to be checked. Iterate through all previous columns, check if there is any placements that lie on two left diagonals.

**Analysis**

Time complexity: O(n^3)

Space complexity: O(n^2)

```python
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def place(col: int, positions: List[int]):
            if col == n:
                outcome.append(positions)
                return
            
            # try to place a queen to one of slots in this column
            for row in range(n):
                # check if this is a valid place
                valid = True
                pn = len(positions)
                for j in range(pn):
                    # 1. check if this row is used
                    if row == positions[j]:
                        valid = False
                        break
                    # check if two left diagonals are used
                    if col-j == abs(row-positions[j]):
                        valid = False
                        break
                if valid:
                    place(col+1, positions + [row])
                
                
        # store list of possible placement, each placement is a list of row value, with index is a column.
        outcome = []
        place(0, [])
        
        # construct the board
        boards = []
        for sol in outcome:
            board = [['.' for _ in range(n)] for _ in range(n)]
            for r, c in enumerate(sol):
                board[r][c] = 'Q'
            boards.append([''.join(r) for r in board])
        return boards
        
```
```
9 / 9 test cases passed.
Status: Accepted
Runtime: 92 ms
Memory Usage: 14.9 MB
```
