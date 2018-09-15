# Week 39

### Reverse Integer

```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var checkSubarraySum = function(nums, k) {
  // handle edge case of k = 0
  if (k === 0) {
    for (let i = 1; i < nums.length; i++) {
      if (nums[i] === 0 && nums[i - 1] === 0) return true;
    }
    return false;
  }

  let moduloMap = {};
  const accumulationArr = Array(nums.length).fill(0);
  for (let i = 0; i < nums.length; i++) {
    accumulationArr[i] = (accumulationArr[i - 1] || 0) + nums[i];
    const modulo = accumulationArr[i] % k;

    moduloMap[modulo] = (moduloMap[modulo] || 2) - 1;
    if ((modulo === 0 && i > 0) || moduloMap[modulo] === 0) return true;
  }
  return false;
};
```

### Word Search

```js
const hashPosition = (x, y) => `${x}_${y}`;
const getCell = (board, x, y) => (board[x] ? board[x][y] : undefined);
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
  for (let i = 0; i < board.length; i++) {
    const row = board[i];
    for (let j = 0; j < row.length; j++) {
      if (search(board, [i, j], word, {})) return true;
    }
  }
  return false;
};

function search(board, startingPosition, word, trackedCell) {
  let [i, j] = startingPosition;
  if (word === "") return true;
  const currentCell = getCell(board, i, j);
  const positionHash = hashPosition(i, j);
  if (!currentCell || trackedCell[positionHash] || currentCell !== word[0])
    return false;
  const newTrackedCell = Object.assign({}, trackedCell, {
    [positionHash]: true
  });
  return (
    search(board, [i - 1, j], word.slice(1), newTrackedCell) ||
    search(board, [i, j - 1], word.slice(1), newTrackedCell) ||
    search(board, [i + 1, j], word.slice(1), newTrackedCell) ||
    search(board, [i, j + 1], word.slice(1), newTrackedCell)
  );
}
```

### Continuous Subarray Sum

```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var checkSubarraySum = function(nums, k) {
  // handle edge case of k = 0
  if (k === 0) {
    for (let i = 1; i < nums.length; i++) {
      if (nums[i] === 0 && nums[i - 1] === 0) return true;
    }
    return false;
  }

  let moduloMap = {};
  const accumulationArr = Array(nums.length).fill(0);
  for (let i = 0; i < nums.length; i++) {
    accumulationArr[i] = (accumulationArr[i - 1] || 0) + nums[i];
    const modulo = accumulationArr[i] % k;

    moduloMap[modulo] = (moduloMap[modulo] || 2) - 1;
    if ((modulo === 0 && i > 0) || moduloMap[modulo] === 0) return true;
  }
  return false;
};
```
