## Problem 1

```ruby
MAX = 2147483647
MIN = -2147483648

def overflow?(x)
  x > MAX || x < MIN
end

def reverse(x)
  result = 0
  abs_number = x.abs
  sign = x.positive? ? 1 : -1

  return 0 if overflow?(x)

  while abs_number > 0
    result = result * 10 + abs_number % 10
    abs_number /= 10
  end

  result *= sign

  overflow?(result) ? 0 : result
end
```
