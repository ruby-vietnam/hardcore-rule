## Problem 1 - [Count and Say](https://leetcode.com/problems/count-and-say/description/)

```ruby

def count_and_say(n)
  return "1" if n == 1

  str = count_and_say(n - 1)
  result = ""

  i = 0
  while i < str.length
    current = str[i]
    count = 1
    j = i + 1

    while j < str.length
      if current == str[j]
        count += 1
        j += 1
      else
        break
      end
    end

    result << "#{count}#{current}"
    i = j
  end

  result
end


```

## Problem 2 - [Elevator Trouble](https://www.spoj.com/problems/ELEVTRBL/)

```ruby

def step(f, start, goal, up, down)
  return 0 if start == goal

  if start < goal
    return "use the stairs" if up == 0

    if (goal - start) % up == 0
      return (goal - start) / up
    else
      return "use the stairs" if down == 0
    end
  end

  if start > goal
    return "use the stairs" if down == 0

    if (start - goal) % down == 0
      return (start - goal) / down
    else
      return "use the stairs" if up == 0
    end
  end

  path = Array.new(f) { |i| i = -1 }
  q = [start]

  while !q.empty? && path[goal] == -1
    v = q.shift

    if start < goal
      u = v + up <= goal ? v + up : v - down
    end

    if start > goal
      u = v - down >= goal ? v - down : v + up
    end

    if path[u] == -1
      path[u] = v
      q.push(u)
    end
  end

  if path[goal] == -1
    return "use the stairs"
  else
    count = 0
    tmp = goal

    while tmp != start
      count += 1
      tmp = path[tmp]
    end

    return count
  end
end

f, start, goal, up, down = gets.chomp.split.map(&:to_i)
puts step(f, start - 1, goal - 1, up, down)


```

## Problem 3 - [Minimize the error](http://codeforces.com/problemset/problem/960/B)

```ruby

n, k1, k2 = gets.chomp.split.map(&:to_i)

a = gets.chomp.split.map(&:to_i)
b = gets.chomp.split.map(&:to_i)

c = Array.new(n) { |i| (a[i] - b[i]).abs }.sort
i = n - 1

(k1 + k2).times do
  c[i] = (c[i] - 1).abs

  current_max = c.max
  if c[i] != current_max
    i_max = c.index(current_max)
    i = i_max
  end
end

min_error = 0
for num in c
  min_error += num * num
end

puts min_error

```
