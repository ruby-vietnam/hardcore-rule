# Problem 1
```ruby
# @param {Integer} n
# @return {Boolean}
def is_power_of_three(n)
  return false if n <= 0
  while n > 1
    return false unless n % 3 == 0
    n /= 3
  end
  true
end
```
