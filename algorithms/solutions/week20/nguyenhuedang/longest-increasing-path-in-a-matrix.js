/**
 * @param {number[][]} matrix
 * @return {number}
 */

var longestIncreasingPath = function(matrix) {
  let max = 0;
  const result = matrix.map(row => row.map(_ => 1));
  const visited = matrix.map(row => row.map(_ => false));

  const visit = (x, y) => {
    const directions = [[0, -1], [0, 1], [1, 0], [-1, 0]];
    for (const [i, j] of directions) {
      const [u, v] = [x + i, y + j];
      if (!(matrix[u] && matrix[u][v])) { continue; }
      if (matrix[u][v] <= matrix[x][y]) { continue; }
      // ===
      if (
        matrix[u][v] > matrix[x][y] &&
        result[u][v] < result[x][y] + 1
      ) {
        result[u][v] = result[x][y] + 1;
        visit(u, v);
      }
    }
    if (result[x][y] > max) { max = result[x][y]; }
    return result[x][y];
  }

  for (let x = 0; x < matrix.length; ++x) {
    for (let y = 0; y < matrix[0].length; ++y) {
      visit(x, y);
    }
  }
  // Return longest path found
  return max;
};
