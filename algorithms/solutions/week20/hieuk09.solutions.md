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

## Problem 2

```ruby
ZERO_ORD = 48
NINE_ORD = 57
MINUS_ORD = 45
PLUS_ORD = 43
SPACE_ORD = 32
MIN = -2147483648
MAX = 2147483647

def my_atoi(str)
  sum = 0
  numbers = ZERO_ORD..NINE_ORD
  start = false
  flag = 1

  str.each_byte do |c|
    if numbers.include?(c)
      sum = sum * 10 + c - ZERO_ORD
      start = true
    elsif c == MINUS_ORD && start == false
      flag = -1
      start = true
    elsif c == PLUS_ORD && start == false
      flag = +1
      start = true
    elsif c == SPACE_ORD && start == false
      next
    else
      break
    end
  end

  result = sum * flag

  if result < MIN
    MIN
  elsif result > MAX
    MAX
  else
    result
  end
end
```
