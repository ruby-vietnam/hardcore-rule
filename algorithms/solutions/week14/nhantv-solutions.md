# Problem 1: Power of Four

https://leetcode.com/problems/power-of-four/description/

A number is power of four it must satisfy the following:
  + It is power of two[1]. // `num & (num - 1) == 0`
  + It has number of `0` is even[2]. // `num & 1431655765 == num`

```
Runtime: 72 ms
Your runtime beats 33.33 % of ruby submissions.
```

```ruby
# @param {Integer} num
# @return {Boolean}
def is_power_of_four(num)
  return false if num <= 0
  (num & (num - 1) == 0) && (num & 1431655765 == num)
end
```

# Problem 2: Number of Islands

https://leetcode.com/problems/number-of-islands/description/

```
Runtime: 132 ms
Your runtime beats 38.78 % of ruby submissions.
```

```ruby
# @param {Character[][]} grid
# @return {Integer}
def num_islands(grid)
  @row = grid.size
  return 0 if @row == 0
  @column = grid[0].size
  return 0 if @column == 0
  is_lands = 0
  @row.times do |i|
    @column.times do |j|
      next if grid[i][j] == '0'
      is_lands += 1
      find_land(grid, i, j)
    end
  end
  is_lands
end

def find_land(grid, i, j)
  return if grid[i][j] == '0'
  grid[i][j] = '0'
  find_land(grid, i + 1, j) if i + 1 < @row
  find_land(grid, i - 1, j) if i > 0
  find_land(grid, i, j + 1) if j + 1 < @column
  find_land(grid, i, j - 1) if j > 0
end
```
