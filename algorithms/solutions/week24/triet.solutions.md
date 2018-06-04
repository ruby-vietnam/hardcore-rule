## Problem 1

```ruby
# @param {Integer} c
# @return {Boolean}
def judge_square_sum(c)
  saved = {}
  (0..Math.sqrt(c)).each do |a|
    s = a*a
    saved[s] = a
    return true if saved.key?(c-s)
  end
  false
end
```
