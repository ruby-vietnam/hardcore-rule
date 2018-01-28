# Problem 3: Rotate Image

URL: https://leetcode.com/problems/rotate-image/description/

Status:
```
  ✔ Accepted
  ✔ 21/21 cases passed (57 ms)
  ✔ Your runtime beats 33.33 % of ruby submissions
```

```ruby
def rotate(matrix)
  normalize(matrix)
  last = matrix.size -  1
  tmp = nil
  (0..last-1).each do |i|
    (i+1..last).each do |j|
      tmp = matrix[i][j]
      matrix[i][j] = matrix[j][i]
      matrix[j][i] = tmp
    end
  end
  matrix
end

def normalize(matrix)
  last = matrix.size -  1
  half = matrix.size / 2 - 1
  tmp = nil
  (0..half).each do |i|
    tmp = matrix[i]
    matrix[i] = matrix[last - i]
    matrix[last - i] = tmp
  end
end
```
