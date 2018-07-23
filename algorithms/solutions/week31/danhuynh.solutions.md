## Problem 1
```ruby
strings = gets.strip

def solve(strings)
  i = 0
  while i < strings.size
    if strings[i..i+1] == 'AB'
      i += 2
      while i < strings.size
        if strings[i..i+1] == 'BA'
          puts 'YES'
          return
        end
        i += 1
      end
    end
    i += 1
  end
  i = 0
  while i < strings.size
    if strings[i..i+1] == 'BA'
      i += 2
      while i < strings.size
        if strings[i..i+1] == 'AB'
          puts 'YES'
          return
        end
        i += 1
      end
    end
    i += 1
  end
  puts 'NO'
end

solve(strings)
```

## Problem 2
```ruby
# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

def max_path_sum_solve(root, max)
  return nil, max unless root

  max_left, max_1 = max_path_sum_solve(root.left, max)
  max_right, max_2 = max_path_sum_solve(root.right, max)

  max_path = [[max_left.to_i, max_right.to_i].max + root.val, root.val].max

  max_node = [
    max_path,
    root.val + max_left.to_i + max_right.to_i
  ].max

  [max_path, [max_1, max_2, max_node].max]
end

# @param {TreeNode} root
# @return {Integer}
def max_path_sum(root)
  max_path_sum_solve(root, -Float::INFINITY)[1]
end
```

## Problem 3
Naive way n!
Time limit exceeded on test 16
```ruby
def solve
  n, m, k = gets.strip.split.map(&:to_i)
  a = gets.strip.split.map(&:to_i)
  idx = (0..n-1).to_a
  rules = Array.new(18) {Array.new(18){0}}
  k.times do
    x, y, c = gets.strip.split.map(&:to_i)
    rules[x-1][y-1] = c
  end

  $max = 0
  permutation(a, idx, 0, m, 0, rules)
  puts $max
end

def permutation(a, idx, start, m, total, rules)
  if start == m
    if total > $max
      $max = total
    end
  else
    start.upto(idx.size-1) do |i|
      idx[i], idx[start] = idx[start], idx[i]
      old_total = total

      total += a[idx[start]]
      if start > 0 && rules[idx[start]] && rules[idx[start]][idx[start-1]]
        total += rules[idx[start][idx[start-1]]
      end

      permutation(a, idx, start + 1, m, total, rules)

      total = old_total
      idx[i], idx[start] = idx[start], idx[i]
    end
  end
end

solve
```

DP chom tu @taurandat
```ruby
def count_set_bit(x)
  b = 0
  while x > 0
    x &= x - 1
    b += 1
  end
  return b
end


def solve
  n, m, k = gets.strip.split.map(&:to_i)
  rules = Array.new(18) {Array.new(18) {0}}

  # this array hold the max satisfactions of all states
  # a state of selection gonna be represented by a bit mask
  # eg: 1011 -> means eating a[0], a[1] and a[3]
  # the easiest way to generate all the states is using the shift operater
  # eg: 1 -> (1 << 4 - 1) is same as
  #    1    2    3    4    5    6    7    8    9   10   11   12   13   14
  # 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1111
  # Note that we need to save diffent maxes for diffent last eaten dishes
  satisfactions = Array.new(1 << n) {Array.new(18) {0}}


  # answer
  max = 0

  a = []
  gets.strip.split.each_with_index do |x, i|
    a[i] = x.to_i
    satisfactions[1 << i][i] = a[i]
    if m == 1
      max = [max, a[i]].max
    end
  end

  if m == 1
    puts max
    return
  end

  k.times do
    x, y, c = gets.strip.split.map(&:to_i)
    rules[x-1][y-1] = c
  end

  # loop through all state
  1.upto((1<<n)-1) do |state|
    # skip if we ate more than needed
    next if count_set_bit(state) > m
    # Loop through all dishes to choose the next dish to eat
    # Create a new state for each next dishes
    # and updating the max satisfaction for that new state
    0.upto(n-1) do |i|
      # check if we ate this dish or not
      # if it isn't eaten then we can eat it next
      next unless (state >> i) & 1 == 0
      # Loop through all dishes
      new_state = nil
      0.upto(n-1) do |j|
        # check if we ate this dish
        # and use it as the last eaten dish
        next unless (state >> j) & 1 > 0
        new_state = state | 1 << i
        # update the max satisfaction of this new state
        # it is equal to the sum of satisfaction of the new dish,
        # bonus, and satisfaction from the current state
        satisfactions[new_state][i] = [
          satisfactions[new_state][i],
          a[i] + rules[j][i] + satisfactions[state][j]
        ].max
      end

      # update max
      if count_set_bit(state) == m - 1
        max = [max, satisfactions[new_state][i]].max
      end
    end
  end

  puts max
end

solve
```

## Problem 4
Naive way n^2
```ruby
# @param {Integer[]} a
# @param {Integer} k
# @return {Integer}
def shortest_subarray(a, k)
  sum_arr = Array.new(a.size) { [] }
  shortest_length = Float::INFINITY

  0.upto(a.size-1) do |i|
    i.downto(0) do |j|
      break if shortest_length == 1
      if i == j
        sum_arr[i][j] = a[i]
      else
        sum_arr[i][j] = sum_arr[i][i] + sum_arr[i-1][j]
      end
      if sum_arr[i][j] >= k && (i - j + 1 < shortest_length)
        shortest_length = i - j + 1
      end
    end
  end

  shortest_length == Float::INFINITY ? -1 : shortest_length
end
```

n way
```ruby
# @param {Integer[]} a
# @param {Integer} k
# @return {Integer}
def shortest_subarray(a, k)
  sum_befores = [0]
  min = a.size+1
  start_points = []
  start_index = 0
  end_index = 0
  cur_sum = 0
  while end_index < a.size
    cur_sum += a[end_index]
    sum_befores[end_index+1] = cur_sum
    end_index += 1

    while start_points.size > 0 && cur_sum - sum_befores[start_points.first] >= k
      start_index = start_points.shift
    end

    if cur_sum - sum_befores[start_index] >= k && end_index - start_index < min
      min = end_index - start_index
    end

    while start_points.size > 0 && cur_sum <= sum_befores[start_points.last].to_i
      start_points.pop
    end

    start_points << end_index
  end

  min > a.size ? -1 : min
end
```
