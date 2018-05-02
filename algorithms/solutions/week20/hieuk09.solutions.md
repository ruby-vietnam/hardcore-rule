## Problem 1

```ruby
def plus_one(digits)
  result = []
  digits[digits.size - 1] += 1

  flag = 0
  digits.reverse.each do |digit|
    digit += flag
    num = digit % 10
    flag = digit / 10
    result << num
  end

  if flag.positive?
    result << flag
  end

  result.reverse
end
```
