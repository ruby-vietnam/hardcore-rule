## Problem 1

https://leetcode.com/problems/plus-one/description/

```ruby
# @param {Integer[]} digits
# @return {Integer[]}
def plus_one(digits)
    remain = 1
    index = digits.length - 1
    loop do
        digits[index] += remain
        remain = digits[index] / 10
        digits[index] = digits[index] % 10
        index -= 1
        break if index < 0 || remain == 0
    end
    digits.unshift(remain) if remain != 0
    digits
end
```

## Problem 3

https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

Spread algorithm, split into 2 categories: increasing and decreasing. At a point, check the four next adjancent cells. If that cell is bigger and the current route is to find increasing array and the length[current cell] + 1 > length[next cell], add that cell and route into the queue.

```ruby
# @param {Integer[][]} matrix
# @return {Integer}
INCREASE = :increase
DECREASE = :decrease
DONE = :done

DELTA_X = [0, 1, 0, -1]
DELTA_Y = [-1, 0, 1, 0]

def longest_increasing_path(matrix)
    x_max = matrix.length
    return 0 if x_max == 0
    y_max = matrix[0].length
    return 0 if y_max == 0

    length = Array.new(matrix.length) do
        Array.new(matrix[0].length) do
            {INCREASE => 1, DECREASE => 1, DONE => false}
        end
    end

    matrix.each_with_index do |row, root_x|
        row.each_with_index do |_, root_y|
            next if length[root_x][root_y][DONE]
            queue = [[root_x, root_y, INCREASE],[root_x, root_y, DECREASE]]
                
            loop do
                break if queue.empty?
                x, y, finding = queue.pop
                4.times do |direction|
                    next_x = x + DELTA_X[direction]
                    next_y = y + DELTA_Y[direction]
                    next if next_x < 0 || next_x >= x_max || next_y < 0 || next_y >= y_max
                    if matrix[next_x][next_y] > matrix[x][y] && finding == INCREASE
                        if length[x][y][INCREASE] + 1 > length[next_x][next_y][INCREASE]
                            length[next_x][next_y][INCREASE] = length[x][y][INCREASE] + 1
                            queue << [next_x, next_y, INCREASE]
                        end
                    elsif matrix[next_x][next_y] < matrix[x][y] && finding == DECREASE
                        if length[x][y][DECREASE] + 1 > length[next_x][next_y][DECREASE]
                            length[next_x][next_y][DECREASE] = length[x][y][DECREASE] + 1
                            queue << [next_x, next_y, DECREASE]
                        end
                    end
                end
            end
            
            length[root_x][root_y][DONE] = true
        end
    end

    longest = 1
    length.each do |row|
        row.each do |l|
            longest = l[INCREASE] if l[INCREASE] > longest
            longest = l[DECREASE] if l[DECREASE] > longest
        end
    end
    longest
end
```
