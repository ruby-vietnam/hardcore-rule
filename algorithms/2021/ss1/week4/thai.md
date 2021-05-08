## 1812. Determine Color of a Chessboard Square

https://leetcode.com/problems/determine-color-of-a-chessboard-squar

```
Runtime: 28 ms, faster than 84.05% of Python3 online submissions for Determine Color of a Chessboard Square.
Memory Usage: 14.3 MB, less than 7.66% of Python3 online submissions for Determine Color of a Chessboard Square.
```

```python
def whiteCol(row: int) -> bool: return row % 2 == 0
def blackCol(row: int) -> bool: return row % 2 != 0

class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        cases = {
            'a': whiteCol,
            'b': blackCol,
            'c': whiteCol,
            'd': blackCol,
            'e': whiteCol,
            'f': blackCol,
            'g': whiteCol,
            'h': blackCol
        }
        return cases.get(coordinates[0])(int(coordinates[1]))
```

## 935. Knight Dialer

```
Runtime: 380 ms, faster than 85.11% of Python3 online submissions for Knight Dialer.
Memory Usage: 14.4 MB, less than 52.96% of Python3 online submissions for Knight Dialer.
```

```python
def solve(n):
    p = [2,2,2,2,3,0,3,2,2,2]
    m = 1_000_000_007

    if n == 1: return 10

    for i in range(3, n+1):
        pp = [
            (p[4] + p[6]),
            (p[6] + p[8]),
            (p[7] + p[9]),
            (p[4] + p[8]),
            (p[3] + p[9] + p[0]),
            (0),
            (p[1] + p[7] + p[0]),
            (p[2] + p[6]),
            (p[1] + p[3]),
            (p[2] + p[4]),
        ]
        p = pp
    # print(p)
    return sum(p) % m

class Solution:
    def knightDialer(self, n: int) -> int:
        return solve(n)
```

## 51. N-Queens

```
Runtime: 752 ms, faster than 5.02% of Python3 online submissions for N-Queens.
Memory Usage: 14.9 MB, less than 11.99% of Python3 online submissions for N-Queens.
```

```python
def solve(n):
    result = []
    board = []

    for i in range(n):
        board.append([])
        for j in range(n):
            board[i].append('.')

    def placeQueen(r):
        if r == n:
            # print('Find valid board:')
            # print(board)
            result.append([])
            for r in range(n):
                result[-1].append(''.join(board[r]))

        for c in range(n):
            # print(f'Checking {r},{c}')
            # print(board)
            if board[r][c] == '.':
                board[r][c] = 'Q'
                markCell(r, c)
                # print(f'Placed Queen at {r},{c}')
                # print(board)
                placeQueen(r + 1)
                board[r][c] = '.'
                remarkBoard()

    def remarkBoard():
        for r in range(n):
            for c in range(n):
                if board[r][c] != 'Q':
                    board[r][c] = '.'
        for r in range(n):
            for c in range(n):
                if board[r][c] == 'Q':
                    markCell(r, c)

    def markCell(r, c):
        for i in range(n):
            if board[r][i] != 'Q': board[r][i] = 'x'
            if board[i][c] != 'Q': board[i][c] = 'x'
        for i in range(1, n):
            x = r + i; y = c + i
            if valid(x, y): board[x][y] = 'x'
            x = r - i; y = c + i
            if valid(x, y): board[x][y] = 'x'
            x = r + i; y = c - i
            if valid(x, y): board[x][y] = 'x'
            x = r - i; y = c - i
            if valid(x, y): board[x][y] = 'x'

    def valid(r, c):
        return r >= 0 and r < n and c >= 0 and c < n

    placeQueen(0)

    for rs in result:
        for r in range(n):
            rs[r] = rs[r].replace('x', '.')
    return result


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        return solve(n)
```
