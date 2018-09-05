# Problem 1

```ruby
def climb_stairs(n)
  return n if n <= 2
  a, b, c = 1, 2, 0
  (n - 2).times do
    c = a + b
    a = b
    b = c
  end
  c
end
```
