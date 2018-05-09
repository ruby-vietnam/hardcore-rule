# Problemm 1: Nim game

URL: https://leetcode.com/problems/nim-game/description/

Status;
```
  ✔ Accepted
  ✔ 60/60 cases passed (40 ms)
```

```ruby
def can_win_nim(n)
    n % 4 != 0
end
```

# Problemm 2: Teemo Attacking

URL: https://leetcode.com/problems/teemo-attacking/description/

Status;
```
  ✔ Accepted
  ✔ 39/39 cases passed (68 ms)
```

```ruby
def find_poisoned_duration(time_series, duration)
  size = time_series.size
  i = 0
  poisoned_duration = 0
  while i < (size - 1) do
    poisoned_duration += if time_series[i+1] - time_series[i] < duration
      time_series[i+1] - time_series[i]
    else
      duration
    end
    i += 1
  end
  poisoned_duration += duration if size > 0
  poisoned_duration
end
```

