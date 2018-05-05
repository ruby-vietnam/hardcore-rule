# Problem 1: 66 - Plus one

Status:
```
  ✔ Accepted
  ✔ 109/109 cases passed (36 ms)
  ✔ Your runtime beats 75.41 % of ruby submissions
```

```ruby
def plus_one(digits)
  last_index = digits.size - 1
  while last_index >= 0 do
    if digits[last_index] == 9
      digits[last_index] = 0
    else
      digits[last_index] += 1
      break
    end
    last_index -= 1
  end

  last_index.negative? ? digits.unshift(1) : digits
end
```

# Problem 2: 8 - String to integer atoi

Status:
```
  ✔ Accepted
  ✔ 1079/1079 cases passed (56 ms)
  ✔ Your runtime beats 32.35 % of ruby submissions
```

```ruby
INT_MAX = 2**31 - 1
INT_MIN = 0 - 2**31

def my_atoi(str)
  str.strip!
  sign, _zeros, number = str.scan(/^([-|+]?)(0*)(\d+)/).flatten
  number = Integer([sign, number || 0].join(''))
  return INT_MAX if number > INT_MAX
  return INT_MIN if number < INT_MIN
  number
end
```