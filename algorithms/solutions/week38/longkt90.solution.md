# Problem 4 : Basic calculator

URL: https://leetcode.com/problems/basic-calculator/description/

```ruby
def evaluate(tokens, start_index, last_index)
  val = 0
  while start_index <= last_index
    if tokens[start_index] == '('
      start_index += 1
      level = 1
      end_index = start_index
      while level > 0
        case tokens[end_index]
        when '('
          level += 1
        when ')'
          level -= 1
        end
        end_index += 1
      end
      if start_index == 1 || tokens[start_index-2] == '+'
        val += evaluate(tokens, start_index, end_index - 1)
      else
        val -= evaluate(tokens, start_index, end_index - 1)
      end
      start_index = end_index
    end

    next start_index += 1 if tokens[start_index + 1] == '('

    case tokens[start_index]
    when '+'
      val += tokens[start_index + 1].to_i
      start_index += 2
    when '-'
      val -= tokens[start_index + 1].to_i
      start_index += 2
    else
      val += tokens[start_index].to_i
      start_index += 1
    end
  end
  val
end

def calculate(s)
  tokens = s.split(/(\(|\)|\+|-|\s)/).delete_if { |token| token == ' ' || token == ''}
  start_index = 0
  last_index = tokens.size - 1
  evaluate(tokens, start_index, last_index)
end
```
