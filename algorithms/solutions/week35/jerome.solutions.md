## Problem 3 (https://leetcode.com/contest/weekly-contest-97/problems/possible-bipartition/)
```ruby

def possible_bipartition(n, dislikes)
  hash = Hash.new { |hash, key| hash[key] = [] }
  for k, v in dislikes
    hash[k - 1] << v - 1
    hash[v - 1] << k - 1
  end

  color = Array.new(n) { |i| -1 }
  q = [0]
  color[0] = 1

  while !q.empty?
    u = q.shift

    for i in 0..(hash[u].length - 1)
      v = hash[u][i]
      if color[v] == -1
        color[v] = -color[u]
        q.push(v)
      elsif color[v] == color[u]
        return false
      end
    end
  end

  true
end

```
