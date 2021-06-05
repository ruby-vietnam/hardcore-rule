## 155. Min Stack

https://leetcode.com/problems/min-stack/

Use a parallel stack to store min values.

Time complexity: `O(1)`
Space complexity: `O(N)`

```
Runtime: 116 ms, faster than 46.09% of Ruby online submissions for Min Stack.
Memory Usage: 213.9 MB, less than 20.00% of Ruby online submissions for Min Stack.
```

```ruby
class MinStack

=begin
    initialize your data structure here.
=end
    def initialize()
      @min = nil
      @stack = []
      @min_vals = []
    end


=begin
    :type val: Integer
    :rtype: Void
=end
    def push(val)
      @stack << val
      if @min == nil
        @min = val
      else
        @min = [@min, val].min
      end
      @min_vals << @min
    end


=begin
    :rtype: Void
=end
    def pop()
      @stack.pop
      @min_vals.pop
      @min = @min_vals.last
    end


=begin
    :rtype: Integer
=end
    def top()
      @stack.last
    end


=begin
    :rtype: Integer
=end
    def get_min()
      @min
    end


end

# Your MinStack object will be instantiated and called as such:
# obj = MinStack.new()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.get_min()
```

## 200. Number of Islands

https://leetcode.com/problems/number-of-islands/

Check each points, use DFS/BFS to mark visited lands. The number of time we start a new marking is the number of islands.

Time Complexity: `O(NxM)`

```
Runtime: 84 ms, faster than 80.19% of Ruby online submissions for Number of Islands.
Memory Usage: 215.6 MB, less than 18.36% of Ruby online submissions for Number of Islands.
```

```ruby
# @param {Character[][]} grid
# @return {Integer}
def num_islands(grid)
  # pp '-'*100
  @dd = [
    [-1, 0],
    [1, 0],
    [0, -1],
    [0, 1]
  ]
  @grid = grid
  @n = grid.size
  @m = grid[0].size
  @visited = Array.new(@n) { |_index| Array.new(@m, false) }
  count = 0
  
  # pp "@visited is #{@visited}"
  for i in 0..@n-1
    for j in 0..@m-1
      if grid[i][j] == '1' && !@visited[i][j]
        count += 1
        # pp "Visiting new island starting from #{i},#{j}"
        visit(i, j)
        # pp "@visited is #{@visited}"
      end
    end
  end
  
  count
end

def visit(x, y)
  # @grid[x][y] = '0'
  # pp "Visiting cell #{x},#{y}"
  @visited[x][y] = true
  for k in 0..3
    xx = x + @dd[k][0]
    yy = y + @dd[k][1]
    if valid(xx, yy) && @grid[xx][yy] == '1' && !@visited[xx][yy]
      visit(xx, yy)
    end
  end
end

def valid(x, y)
  x >= 0 && x < @n && y >= 0 && y < @m
end
```

### By the way, solved similar problem: 695. Max Area of Island

https://leetcode.com/problems/max-area-of-island/

Similar to above problem, add `@area` and `@max_area` to keep track of area while doing DFS/BFS

```
Runtime: 184 ms, faster than 8.47% of Ruby online submissions for Max Area of Island.
Memory Usage: 212.2 MB, less than 6.78% of Ruby online submissions for Max Area of Island.
```

```ruby
# @param {Integer[][]} grid
# @return {Integer}
def max_area_of_island(grid)
  # pp '-'*100
  @dd = [
    [-1, 0],
    [1, 0],
    [0, -1],
    [0, 1]
  ]
  @grid = grid
  @n = grid.size
  @m = grid[0].size
  @visited = Array.new(@n) { |_index| Array.new(@m, false) }
  @max_area = 0
  
  for i in 0..@n-1
    for j in 0..@m-1
      # pp "Checking #{i},#{j}"
      if grid[i][j] == 1 && !@visited[i][j]
        @area = 0
        # pp "Visiting new island starting from #{i},#{j}"
        visit(i, j)
        @max_area = [@max_area, @area].max
      end
    end
  end
  
  @max_area
end

def visit(x, y)
  # pp "Visiting cell #{x},#{y}"
  @visited[x][y] = true
  @area += 1
  for k in 0..3
    xx = x + @dd[k][0]
    yy = y + @dd[k][1]
    if valid(xx, yy) && @grid[xx][yy] == 1 && !@visited[xx][yy]
      visit(xx, yy)
    end
  end
end

def valid(x, y)
  x >= 0 && x < @n && y >= 0 && y < @m
end
```

## 42. Trapping Rain Water

https://leetcode.com/problems/trapping-rain-water/

For each position, search for the tallest in the left, and the tallest in the right of that position.

Can use `tallest_left` and `tallest_right` arrays, to avoid recalculation. These arrays are calculated once at the beginning. Without this improvement, the time complexity is `O(N^2)` and will get `Time Limit Exceeded` verdict.

Time complexity: `O(N)`
Space complexity: `O(N)`

```
Runtime: 116 ms, faster than 13.73% of Ruby online submissions for Trapping Rain Water.
Memory Usage: 210.4 MB, less than 29.41% of Ruby online submissions for Trapping Rain Water.
```

```ruby
# @param {Integer[]} height
# @return {Integer}
def trap(height)
  @height = height
  @n = height.size
  return 0 if @n == 0
  
  @heightest_left = Array.new(@n, -1)
  @heightest_left[0] = @height[0]
  for i in 1..@n-1
    @heightest_left[i] = [@heightest_left[i-1], @height[i]].max 
  end
  # pp "@heightest_left is #{@heightest_left}"
  
  @heightest_right = Array.new(@n, -1)
  @heightest_right[@n-1] = @height[@n-1]
  for i in (@n-2).downto(0)
    @heightest_right[i] = [@heightest_right[i+1], @height[i]].max 
  end
  # pp "@heightest_right is #{@heightest_right}"
  
  res = 0
  for i in 1..@n-2 
    res += get_trapped(i)
  end
  res
end

def get_trapped(x)
  high_left = @heightest_left[x-1]
  high_right = @heightest_right[x+1]
  if high_left > @height[x] && high_right > @height[x]
    trapped = [high_left, high_right].min - @height[x]
    # pp "Adding at #{x} trapped #{trapped}"
    return trapped
  else
    return 0
  end
end
```
