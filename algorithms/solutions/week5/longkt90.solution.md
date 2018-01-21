# Problem 1: Pascal Triangle

URL: https://leetcode.com/problems/pascals-triangle-ii/description/
TODO

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