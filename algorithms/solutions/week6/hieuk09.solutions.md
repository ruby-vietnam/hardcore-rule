## Problem 1

```ruby
def find_shortest_sub_array(nums)
  result = {}
  max_num = nums.first

  nums.each_with_index do |num, index|
    if result[num]
      result[num][0] += 1
      result[num][2] = index
    else
      result[num] = [1, index, index]
    end

    if result[num][0] > result[max_num][0] || (result[num][0] == result[max_num][0] && distance(result[num]) < distance(result[max_num]))
      max_num = num
    end
  end

  distance(result[max_num])
end

def distance(cache)
  cache[2] - cache[1] + 1
end
```

## Problem 2

```ruby
def update_matrix(matrix)
  start = nil
  height = matrix.size
  width = matrix.first.size

  height.times do |i|
    flag = false

    width.times do |j|
      if matrix[i][j] == 0
        start = [i, j]
        flag = true
        break
      end
    end

    break if flag
  end

  queue = Queue.new
  queue << start
  checker = { start => 1 }
  movements = [[-1, 0], [0, -1], [1, 0], [0, 1]]

  while !queue.empty?
    x, y = queue.pop

    movements.each do |delta_x, delta_y|
      new_x = x + delta_x
      new_y = y + delta_y

      next if new_x >= height || new_y >= width || new_x < 0 || new_y < 0

      new_position = [new_x, new_y]

      if checker[new_position].nil?
        checker[new_position] = 1
        queue << new_position

        if matrix[new_x][new_y] != 0
          matrix[new_x][new_y] = matrix[x][y] + 1
        end
      else
        if matrix[new_x][new_y] != 0
          if matrix[new_x][new_y] > matrix[x][y] + 1
            matrix[new_x][new_y] = matrix[x][y] + 1
            queue << new_position
          end
        end
      end
    end
  end

  matrix
end
```

## Problem 3

```ruby
def rotate(matrix)
  size = matrix.size
  rotation_size = (size + 1) / 2

  rotation_size.times do |i|
    if size.odd? && i == rotation_size - 1
      next
    end
    rotation_size.times do |j|
      i2 = size - i - 1
      j2 = size - j - 1
      temp = matrix[i][j]
      matrix[i][j] = matrix[j2][i]
      matrix[j2][i] = matrix[i2][j2]
      matrix[i2][j2] = matrix[j][i2]
      matrix[j][i2] = temp
    end
  end

  matrix
end
```
