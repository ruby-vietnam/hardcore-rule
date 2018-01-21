# Problem 1: Pascal Triangle

URL: https://leetcode.com/problems/pascals-triangle-ii/description/

Status:
```
  ✔ Accepted
  ✔ 34/34 cases passed (55 ms)
  ✔ Your runtime beats 45.45 % of ruby submissions
```

```ruby
# @param {Integer} row_index
# @return {Integer[]}
def get_row(row_index)
  array =  Array.new(row_index + 1, 0)
  array[0] = 1
  return array if row_index < 1
  for i in (1...row_index+1) do
    j = i
    while j > 0 do
      array[j] += array[j-1]
      j -= 1
    end
  end
  array
end

```

# Problem 2: Valid Parenthesis String

URL: https://leetcode.com/problems/valid-parenthesis-string/description/

Status:
```
  ✔ Accepted
  ✔ 58/58 cases passed (55 ms)
  ✔ Your runtime beats 60 % of ruby submissions
```

```ruby
# @param {String} s
# @return {Boolean}
def check_valid_string(s)
  stack = []
  wildcards = []
  s.each_char.with_index do |char, index|
    if char == '*'
      wildcards << { char => index }
    elsif char == '('
      stack << { char => index }
    else char == ')'
      if stack.size > 0
        stack.pop
      else
        if wildcards.size > 0
          wildcards.pop
        else
          return false
        end
      end
    end
  end

  return false if stack.size > wildcards.size

  while(stack.size > 0)
    if stack.pop['('] > wildcards.pop['*']
      return false
    end
  end

  true
end

```

# Problem 3: Russian Doll Envelopes

URL: https://leetcode.com/problems/russian-doll-envelopes/description/

TODO