// https://leetcode.com/contest/weekly-contest-97/problems/spiral-matrix-iii/

function isInMatrix(R, C, r, c) {
  return 0 <= r && r < R && 0 <= c && c < C;
}

/**
 * @param {number} R
 * @param {number} C
 * @param {number} r0
 * @param {number} c0
 * @return {number[][]}
 */
function spiralMatrixIII(R, C, r0, c0) {
  const arr = [[r0, c0]];

  let round = 0;
  let edgeSize = 1;
  let currentRow = r0;
  let currentCol = c0;
  let nextNumber = 2;
  while (nextNumber <= R * C) {
    switch (round % 4) {
      case 0:
        // Go right
        for (let i = 0; i < edgeSize; i++) {
          currentCol += 1;
          if (isInMatrix(R, C, currentRow, currentCol)) {
            arr.push([currentRow, currentCol]);
            nextNumber++;
          }
        }
        break;
      case 1:
        // Go down
        for (let i = 0; i < edgeSize; i++) {
          currentRow += 1;
          if (isInMatrix(R, C, currentRow, currentCol)) {
            arr.push([currentRow, currentCol]);
            nextNumber++;
          }
        }
        edgeSize++;
        break;
      case 2:
        // Go left
        for (let i = 0; i < edgeSize; i++) {
          currentCol -= 1;
          if (isInMatrix(R, C, currentRow, currentCol)) {
            arr.push([currentRow, currentCol]);
            nextNumber++;
          }
        }
        break;
      case 3:
        // Go up
        for (let i = 0; i < edgeSize; i++) {
          currentRow -= 1;
          if (isInMatrix(R, C, currentRow, currentCol)) {
            arr.push([currentRow, currentCol]);
            nextNumber++;
          }
        }
        edgeSize++;
        break;
    }
    round++;
  }

  return arr;
}
