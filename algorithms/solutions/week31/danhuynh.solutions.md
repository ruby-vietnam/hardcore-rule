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

## Problem 4
Naive way
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

log(n) way
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
