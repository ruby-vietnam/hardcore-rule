# Problem 1

```ruby
def hamming_distance(x, y)
  (x ^ y).to_s(2).count('1')
  end
```
