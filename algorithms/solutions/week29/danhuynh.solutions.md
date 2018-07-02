## Problem 1
```ruby
# @param {Integer} n
# @return {String}
def count_and_say(n)
  result = "1"
  2.upto(n) do
    next_result = ""
    count = 0
    num = result[0]
    result.each_char do |c|
      next count += 1 if num == c
      next_result += "#{count}#{num}"
      num = c
      count = 1
    end
    next_result += "#{count}#{num}"
    result = next_result
  end
  result
end
```

## Problem 2
```ruby
```
