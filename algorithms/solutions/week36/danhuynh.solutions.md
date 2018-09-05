# Problem 1
```ruby
# @param {Integer} n
# @return {Integer}
def climb_stairs(n)
  s1, s2 = 1, 1

  while n > 0
    temp = s2
    s2 += s1
    s1 = temp
    n -= 1
  end

  s1
end
```

# Problem 2
```ruby
# @param {String} s
# @return {Integer}
def length_of_longest_substring(s)
  hash = {}
  max = 0
  length = 0

  s.each_char.with_index do |c, i|
    position = hash[c]

    if position && position >= i - length
      length = i - position
    else
      length += 1
    end

    max = length if length > max

    hash[c] = i
  end

  max
end
```
