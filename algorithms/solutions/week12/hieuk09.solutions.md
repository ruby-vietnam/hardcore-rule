## Problem 1

```ruby
def can_win_nim(n)
  n % 4 != 0
end
```

## Problem 2

```ruby
def find_poisoned_duration(time_series, duration)
  return 0 if time_series.empty?

  max_moment = time_series.first
  total_time = duration

  time_series.each do |moment|
    if moment >= max_moment + duration
      total_time += duration
    elsif moment > max_moment
      total_time += moment - max_moment
    end

    max_moment = moment
  end

  total_time
end
```
