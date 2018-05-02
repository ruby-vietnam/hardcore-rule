/**
 * @param {number[][]} matrix
 * @return {number}
 */
var longestIncreasingPath = function(matrix) {
  let max = 0;

  // All cells have path of length 1 itself without any travelling
  const result = matrix.map(row => row.map(_ => 1));

  // Visit the cell with cors x y
  const visit = (x, y) => {
    const directions = [[0, -1], [0, 1], [1, 0], [-1, 0]];
    for (const [dx, dy] of directions) {
      const [u, v] = [x + dx, y + dy];
      // Try to compute matrix[u][v]
      // If we're out of the boundary, we just catch err and do nothing
      try {
        if (
          // We could visit [u][v]
          matrix[u][v] > matrix[x][y] &&
          // And visiting [u][v] could improve result of [u][v]
          result[u][v] < result[x][y] + 1
        ) {
          // Update result
          result[u][v] = result[x][y] + 1;
          // And explore
          visit(u, v);
        }
      } catch(_) {}
    }
    if (result[x][y] > max) { max = result[x][y]; }
    return result[x][y];
  }

  // Try to visit all cells
  for (let x = 0; x < matrix.length; ++x) {
    for (let y = 0; y < matrix[0].length; ++y) {
      visit(x, y);
    }
  }

  // Return longest path found
  return max;
};
