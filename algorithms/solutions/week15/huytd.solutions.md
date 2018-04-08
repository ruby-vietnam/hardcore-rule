# Problem 1: Move Zeroes

URL: https://leetcode.com/problems/move-zeroes/description/

```
  ✔ Accepted
  ✔ 21/21 cases passed (120 ms)
  ✔ Your runtime beats 13.19 % of javascript submissions
```

I did this on my own, I'm not copy from @qcam

```javascript
const moveZeroes = (nums) => {
    let target = 0;
    for (let i = 0; i < nums.length; i++) {
        let num = nums[i];
        if (num !== 0) {
            nums[i] = 0;
            nums[target] = num;
            target++;
        }
    }
};
```

# Bonus Problem: Sudoku Solver

URL: https://leetcode.com/problems/sudoku-solver/description/

Status:

```
  ✔ Accepted
  ✔ 6/6 cases passed (160 ms)
  ✔ Your runtime beats 55.17 % of javascript submissions
```

Implement: Just a naive trial and error solution (backtracking).

```javascript
const SIZE = 9;
const CELL = 3;

var solveSudoku = function(board) {
    trialAndError(board);
};

const trialAndError = function(board) {
    for (let y = 0; y < SIZE; y++) {
        for (let x = 0; x < SIZE; x++) {
            if (board[y][x] === '.') {
                for (let i = 1; i <= 9; i++) {
                    if (checkBoard(board, i + '', y, x)) {
                        board[y][x] = i + '';

                        if (trialAndError(board)) {
                            return true;
                        } else {
                            board[y][x] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
};

const checkBoard = (board, move, r, c) => {
    for (let i = 0; i < SIZE; i++) {
        let x = CELL * ~~(r / CELL) + ~~(i / CELL);
        let y = CELL * ~~(c / CELL) + ~~(i % CELL);
        if (board[i][c] !== '.' && board[i][c] === move) return false;
        if (board[r][i] !== '.' && board[r][i] === move) return false;
        if (board[x][y] !== '.' && board[x][y] === move) return false;
    }
    return true;
};
```
