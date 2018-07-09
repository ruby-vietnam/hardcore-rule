## Problem 1
```ruby
# @param {Integer} n
# @return {String}
def count_and_say(n)
  result = "1"
  2.upto(n) do
    next_result = ""
    count = 0
    num = result[0]
    result.each_char do |c|
      next count += 1 if num == c
      next_result += "#{count}#{num}"
      num = c
      count = 1
    end
    next_result += "#{count}#{num}"
    result = next_result
  end
  result
end
```

## Problem 2
```ruby
def find_route(floors, start, goal, up, down)
  queue = []
  visited = array.new(floors+1) {false}
  queue << [start, 0]
  step = 0
  while queue.size > 0
    current_floor, steps = queue.shift
    visited[current_floor] = true
    return steps if current_floor == goal
    up_floor = current_floor + up
    queue << [up_floor, steps + 1] if up_floor <= floors && !visited[up_floor]
    down_floor = current_floor - down
    queue << [down_floor, steps + 1] if down_floor > 0 && !visited[down_floor]
    return steps + 1 if down_floor == goal || up_floor == goal
  end
  false
end

f, s, g, u, d = gets.rstrip.split(' ').map(&:to_i)

puts(find_route(f, s, g, u, d) || 'use the stairs')
```

## Problem 3
```ruby
def find_optimal_avg(num1, num2, moves_1, moves_2)
  avg = (num1 + num2) / 2.0
  if (avg.ceil - num1) <= moves_1 && (avg.ceil - num2) <= moves_2
    avg.ceil
  else
    avg.floor
  end
end

def find_optimal_move(moves_left, start, goal)
  optimal_move = goal - start
  if optimal_move.abs <= moves_left
    moves_left -= optimal_move.abs
  else
    optimal_move = moves_left * optimal_move / optimal_move
    moves_left = 0
  end
  [optimal_move, moves_left]
end

def minimize_error(n, k1, k2, arr1, arr2)
  0.upto(n - 1).each do |i|
    avg = find_optimal_avg(arr1[i], arr2[i], k1, k2)
    o1, k1 = find_optimal_move(k1, arr1[i], avg)
    arr1[i] += o1
    o2, k2 = find_optimal_move(k2, arr2[i], avg)
    arr2[i] += o2
    if i == n - 1
      arr1[i] += k1 % 2
      arr2[i] += k2 % 2
    end
  end
  0.upto(n-1).reduce(0){|sum, i| sum + (arr1[i] - arr2[i]) ** 2}
end
```

## Problem 4
```ruby
require 'set'

@memorize_hash = {}

def cal_mex(set)
  (0..Float::INFINITY).each do |i|
    return i unless set.include?(i)
  end
end

def possible_moves(start, stone_count, previous_moves, moves)
  (start..(stone_count/2)).each do |i|
    if stone_count - i > i
      moves << previous_moves + [i, stone_count - i]
      possible_moves(i + 1, stone_count - i, previous_moves + [i], moves)
    end
  end
end

def cal_grundy(stone_count)
  return 0 if stone_count <= 2
  return 1 if stone_count == 3
  return @memorize_hash[stone_count] if @memorize_hash[stone_count]

  set = Set.new

  moves = []
  possible_moves(1, stone_count, [], moves)
  moves.each do |moves|
    grundy = moves.reduce(0){|sum, stones| sum ^ cal_grundy(stones)}
    set.add(grundy)
  end

  @memorize_hash[stone_count] = cal_mex(set)
  @memorize_hash[stone_count]
end

#
# Complete the stonePiles function below.
#
def stonePiles(arr)
  sum_grundy = arr.reduce(0){|sum, stone_count| sum ^ cal_grundy(stone_count)}
  sum_grundy > 0 ? 'ALICE' : 'BOB'
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

t = gets.to_i

t.times do |t_itr|
    arr_count = gets.to_i

    arr = gets.rstrip.split(' ').map(&:to_i)

    result = stonePiles arr

    fptr.write result
    fptr.write "\n"
end

fptr.close()
```
