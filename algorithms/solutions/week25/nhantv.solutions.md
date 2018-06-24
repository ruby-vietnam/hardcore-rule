# Problem 1: Keyboard Row

https://leetcode.com/problems/keyboard-row/description/

```
Runtime: 32 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {String[]} words
# @return {String[]}
def find_words(words)
  first = /^[qwertyuiop]+$/
  second = /^[asdfghjkl]+$/
  third = /^[zxcvbnm]+$/
  words.select { |word| first =~ word.downcase || second =~ word.downcase || third =~ word.downcase }
end
```

# Problem 2: Friend Circles

https://leetcode.com/problems/friend-circles/description/

```
Runtime: 60 ms
Your runtime beats 77.78 % of ruby submissions.
```

```ruby
# @param {Integer[][]} m
# @return {Integer}
def find_circle_num(m)
  values = (0...m.size).to_a
  (0...m.size).each do |i|
    values = find_friend(values, m, i)
  end
  values.uniq.size
end
def find_friend(values, m, i)
  (0...m.size).each do |j|
    if m[i][j] == 1 && values[i] != values[j]
      values[j] = values[i]
      find_friend(values, m, j)
    end
  end
  return values
end
```
