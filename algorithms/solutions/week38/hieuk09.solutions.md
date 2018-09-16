## Problem 1

```ruby
def path_sum(root, sum)
  if root.nil?
    0
  else
    _, count = path_sum_of_tree(root, sum)
    count
  end
end

def path_sum_of_tree(root, sum)
  if root.left && root.right
    left_sums, left_count = path_sum_of_tree(root.left, sum)
    right_sums, right_count = path_sum_of_tree(root.right, sum)

    sums = left_sums + right_sums
    count = left_count + right_count
  elsif root.left
    sums, count = path_sum_of_tree(root.left, sum)
  elsif root.right
    sums, count = path_sum_of_tree(root.right, sum)
  else
    sums = []
    count = 0
  end

  result = [root.val] + sums.map { |sum| sum + root.val }
  count += result.inject(0) { |total, item| item == sum ? total + 1 : total }

  [result, count]
end
```

## Problem 2

```ruby
def search_matrix(matrix, target)
  m = matrix.size

  return false if m == 0

  n = matrix.first.size

  start_x = 0
  start_y = 0

  search(matrix, target, start_x, start_y, m - 1, n - 1)
end

def search(matrix, target, start_x, start_y, m, n)
  if start_x < 0 || start_y < 0 || start_x > m || start_y > n
    false
  else
    median_x = (start_x + m + 1) / 2
    median_y = (start_y + n + 1) / 2

    if matrix[median_x][median_y] == target
      true
    elsif matrix[median_x][median_y] > target
      search(matrix, target, start_x, start_y, median_x - 1, median_y - 1) ||
        search(matrix, target, median_x, start_y, m, median_y - 1) ||
        search(matrix, target, start_x, median_y, median_x - 1, n)
    else
      search(matrix, target, median_x + 1, median_y + 1, m, n) ||
        search(matrix, target, median_x + 1, start_y, m, median_y) ||
        search(matrix, target, start_x, median_y + 1, median_x, n)
    end
  end
end
```
