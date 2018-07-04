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
    optimal_move = moves_left * optimal_move/optimal_move
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
