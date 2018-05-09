## Problem 1

https://leetcode.com/problems/power-of-four/description/

Recursive until we could not divide by 4 again. 

```ruby
# @param {Integer} num
# @return {Boolean}
def is_power_of_four(num)
    if num == 1
        return true
    elsif num < 4
        return false
    else
        num % 4 == 0 && is_power_of_four(num / 4)
    end 
end
```

## Problem 2

https://leetcode.com/problems/number-of-islands/description/

BFS. Loop from start to end, if we meet a cell with `1` value and not touched yet, increase the island count and spread from that point. Each adjacent node has the same island id. The result is the max island id.

```ruby
DELTA_X = [-1, 0, 1, 0]
DELTA_Y = [0, 1, 0, -1]

def num_islands(grid)
    flags = []
    island = 0
    grid.each_with_index do |row, x|
        flags[x] ||= []
        row.each_with_index do |cell, y|
            next if cell == '0' || !flags[x][y].nil?
            island += 1
            flags[x][y] = island
            spread(grid, flags, x, y)
        end
    end
    puts flags.inspect
    return island
end

def spread(grid, flags, start_x, start_y)
    queue = [[start_x, start_y]]
    loop do
        x, y = queue.pop
        return if x.nil? || y.nil?
        4.times do |index|
            next_x = x + DELTA_X[index]
            next_y = y + DELTA_Y[index]
            if next_x >= 0 && next_x < grid.length && next_y >= 0 && next_y < grid[0].length
                puts next_x
                puts next_y
                flags[next_x] ||= []
                if grid[next_x][next_y] == '1' && flags[next_x][next_y].nil?
                    flags[next_x][next_y] = flags[start_x][start_y]
                    queue << [next_x, next_y]
                end
            end
        end
    end
end
```
