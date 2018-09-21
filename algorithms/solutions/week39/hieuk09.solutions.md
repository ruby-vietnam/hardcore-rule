## Problem 1

```ruby
MAX = 2147483647
MIN = -2147483648

def overflow?(x)
  x > MAX || x < MIN
end

def reverse(x)
  result = 0
  abs_number = x.abs
  sign = x.positive? ? 1 : -1

  return 0 if overflow?(x)

  while abs_number > 0
    result = result * 10 + abs_number % 10
    abs_number /= 10
  end

  result *= sign

  overflow?(result) ? 0 : result
end
```

## Problem 2

```ruby
DIRECTIONS = [[0, 1], [1, 0], [-1, 0], [0, -1]]

def exist(board, word)
  if board.empty?
    return false
  end

  height = board.size
  width = board.first.size
  size = width * height
  check = Array.new(size) { false }

  height.times do |i|
    width.times do |j|
      char = board[i][j]

      if word.start_with?(char) && run(board, check, i, j, word, 0)
        return true
      end
    end
  end

  false
end

def run(board, check, x, y, word, index)
  if index == word.size - 1
    return true
  end

  check_index = y * board.size + x
  check[check_index] = true

  result = DIRECTIONS.any? do |delta_x, delta_y|
    new_x = x + delta_x
    new_y = y + delta_y
    new_index = index + 1
    new_check_index = new_y * board.size + new_x

    if new_x >= 0 && new_x < board.size && new_y >= 0 && new_y < board.first.size && new_index < word.size && board[new_x][new_y] == word[new_index] && !check[new_check_index]
      run(board, check, new_x, new_y, word, new_index)
    end
  end

  check[check_index] = false

  result
end
```

## Problem 3

```ruby
def check_subarray_sum(nums, k)
  sum = 0
  trace = { 0 => -1 }

  nums.each_with_index do |num, index|
    sum += num

    if k != 0
      sum %= k
    end

    if trace[sum]
      if index - trace[sum] > 1
        return true
      end
    else
      trace[sum] = index
    end
  end

  false
end
```
