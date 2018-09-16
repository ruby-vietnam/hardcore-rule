## Problem 2 (https://leetcode.com/problems/search-a-2d-matrix-ii/description/)

```ruby
def search_matrix(matrix, target)
  return false if matrix.empty?

  num_rows = matrix.length
  num_cols = matrix[0].length
  i = -1
  j = 0
  temp = matrix[i][j]

  while i >= -num_rows && j < num_cols
    if target < temp
      i -= 1
      temp = matrix[i][j] if matrix[i]
    elsif target > temp
      j += 1
      temp = matrix[i][j] if matrix[i][j]
    else
      return true
    end
  end

  false
end

```
