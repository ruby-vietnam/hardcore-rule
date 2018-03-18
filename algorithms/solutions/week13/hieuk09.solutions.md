## Problem 1

```ruby
def maximum_product(nums)
  max_1 = max_2 = max_3 = -9999
  min_1 = min_2 = 9999
  nums.each do |num|
    if max_1 < num
      max_3 = max_2
      max_2 = max_1
      max_1 = num
    elsif max_2 < num
      max_3 = max_2
      max_2 = num
    elsif max_3 < num
      max_3 = num
    end

    if num < min_1
      min_2 = min_1
      min_1 = num
    elsif num < min_2
      min_2 = num
    end
  end

  [max_1 * max_2 * max_3, max_1 * min_1 * min_2].max
end
```

## Problem 2

```ruby
MAX_INT = 2147483647

def abs(number)
  if number.positive?
    number
  else
    -number
  end
end

def generate_multiplications(divisor, dividend)
  index = 1

  [].tap do |result|
    while divisor <= dividend
      result << [index, divisor]
      divisor += divisor
      index += index
    end
  end
end

def divide(dividend, divisor)
  return MAX_INT if divisor.zero?

  result = 0

  flag = (dividend <= 0 && divisor < 0) || (dividend >= 0 && divisor > 0)
  dividend = abs(dividend)
  divisor = abs(divisor)

  divisor_multiplications = generate_multiplications(divisor, dividend)

  divisor_multiplications.reverse.each do |index, item|
    if dividend >= item
      result += index
      dividend -= item
    end
  end


  if flag
    if result > MAX_INT
      MAX_INT
    else
      result
    end
  else
    -result
  end
end

```
