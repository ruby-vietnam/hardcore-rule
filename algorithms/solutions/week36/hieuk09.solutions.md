## Problem 1

```ruby
def climb_stairs(n)
  first = 2
  second = 3

  if n == 1
    1
  elsif n == 2
    first
  elsif n == 3
    second
  else
    (n - 3).times do
      temp = second
      second = first + second
      first = temp
    end

    second
  end
end
```
