# Problem 1: 461 - Hamming Distance

Status:
```
  ✔ Accepted
  ✔ 149/149 cases passed (36 ms)
  ✔ Your runtime beats 75.41 % of ruby submissions
```

```ruby
def hamming_distance(x, y)
  (x ^ y).to_s(2).count('1')
end
```
