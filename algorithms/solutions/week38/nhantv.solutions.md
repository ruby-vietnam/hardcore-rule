# Problem 2: Search a 2D Matrix II

https://leetcode.com/problems/search-a-2d-matrix-ii/description/

```
Runtime: 604 ms
Your runtime beats 13.04 % of ruby submissions.
```

```ruby
# @param {Integer[][]} matrix
# @param {Integer} target
# @return {Boolean}
def search_matrix(matrix, target)
  r2 = matrix.length - 1
  return false if r2 < 0
  c2 = matrix[0].length - 1
  return false if c2 < 0
  return true if matrix[0][0] == target
  r1 = 0
  c1 = 0
  
  while r1 < r2
    m = ((r1 + r2) / 2.0).ceil
    return true if matrix[m][0] == target
    if matrix[m][0] < target
      r1 = m
    else
      r2 = m - 1
    end
  end
  r1.next.times do |i|
    c1 = 0
    while c1 < c2
      m = ((c1 + c2) / 2.0).ceil
      return true if matrix[i][m] == target
      if matrix[i][m] < target
        c1 = m
      else
        c2 = m - 1
      end
    end
  end
  false
end
```
