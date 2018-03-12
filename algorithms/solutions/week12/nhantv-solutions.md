# Problem 1: Nim Game

```
Runtime: 40 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {Integer} n
# @return {Boolean}
def can_win_nim(n)
  return false if n % 4 == 0
  true
end
```

# Problem 2: Teemo Attacking

```
Runtime: 124 ms
Your runtime beats 66.67 % of ruby submissions.
```

```Ruby
# @param {Integer[]} time_series
# @param {Integer} duration
# @return {Integer}
def find_poisoned_duration(time_series, duration)
  len = time_series.length
  return 0 if len == 0
  sum = duration
  (len - 1).times do |i|
    if time_series[i + 1] - time_series[i] > duration
      sum += duration
    else
      sum += time_series[i + 1] - time_series[i]
    end
  end
  sum
end
```
