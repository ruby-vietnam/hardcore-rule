## Problem 1

```ruby
# @param {String[]} words
# @return {String[]}

def create_map
  keyboard = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]

  map = Hash.new { |hash, key| hash[key] = 0 }

  for i in 0..2
    for j in 0..(keyboard[i].length - 1)
      map[keyboard[i][j]] = i
      map[keyboard[i][j].upcase] = i
    end
  end

  map
end

def same_row?(word, map)
  anchor = map[word[0]]

  for char in word.split("")
    if map[char] != anchor
      return false
    end
  end

  true
end

def find_words(words)
  map = create_map

  result = []

  for word in words
    result.push(word) if same_row?(word, map)
  end

  result
end
```

## Problem 2

```ruby
# @param {String[]} words
# @return {String[]}

def dfs(s, matrix, visited)
  visited[s] = true

  for i in 0..(matrix[s].length - 1)
    if !visited[i] && matrix[s][i] == 1
      dfs(i, matrix, visited)
    end
  end
end

def find_circle_num(m)
  visited = Hash.new { |hash, key| hash[key] = false }

  count_group = 0
  for i in 0..(m.length - 1)
    if !visited[i]
      count_group += 1
      dfs(i, m, visited)
    end
  end

  count_group
end
```
