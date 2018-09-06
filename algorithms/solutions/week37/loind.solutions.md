# Problem 1

```ruby
def is_power_of_three(n)
  return false if n < 1
  while (n % 3).zero?
    n = n/3
  end
  return n == 1
end
```
