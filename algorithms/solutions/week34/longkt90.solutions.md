## Problem 1: House Robber
URL: https://leetcode.com/problems/house-robber/description/


Status:
```
  ✔ Accepted
```

```ruby
def rob(houses)
  houses_count = houses.size
  return 0 if houses_count.zero?
  if houses_count < 3
    houses.max
  elsif houses_count < 4
    [houses[1], houses[0] + houses[2]].max
  else
    houses[2] += houses[0]
    max = houses[2]
    for i in (3..houses_count - 1)
      houses[i] += [houses[i - 2], houses[i - 3]].max
      max = houses[i] if houses[i] > max
    end
    max
  end
end
```

## Problem 2

```ruby
# 26 / 36 test cases passed.
# Time Limit Exceeded
def word_break(string, words_dict)
  (1..words_dict.size).each do |size_of_dict|
    words_dict.permutation(size_of_dict) do |dict|
      tmp_string = string.clone
      dict.each do |word|
        tmp_string = tmp_string.split(word).join(' ')
      end
      return true if tmp_string.strip.empty?
    end
  end
  false
end

# 29 / 36 test cases passed.
# Time Limit Exceeded
def word_break(string, words_dict)
  return true if string.empty?
  words_dict.each do |word|
    result = word_break(string[word.size..-1], words_dict) if string.start_with?(word)
    return true if result
  end
  false
end

# 36 / 36 test cases passed.
# Status: Accepted
# Runtime: 116 ms
def word_break(string, words_dict)
  string_break_points = Array.new(string.size) { false }
  for position in 0..string.size-1
    string_break_points[position] = true if words_dict.include?(string[0..position])
    if string_break_points[position] # can break here - check if we can continue to break
      for another_position in position..string.size-1
        string_break_points[another_position] = true if words_dict.include?(string[position+1..another_position])
        return true if string_break_points[another_position] && another_position == string.size-1
      end
    end
  end
  false
end

 ```
