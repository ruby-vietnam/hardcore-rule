bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
  int i = 0;
  int j = matrixColSize - 1;

  while(i < matrixRowSize && j >= 0) {
    if(matrix[i][j] == target)
      return true;

    if(matrix[i][j] < target)
      ++i;
    else
      --j;
  }

  return false;
}
