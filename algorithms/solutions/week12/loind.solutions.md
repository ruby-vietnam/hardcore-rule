# Problem 1

```ruby
def can_win_nim(n)
    n % 4 != 0
end
```

# Problem 2

```ruby
def find_poisoned_duration(arr, dur)
    n = arr.size
    return 0 if n == 0
    return dur if n == 1
    i = 0
    poi = 0
    while i < (n - 1)
        per = arr[i + 1] - arr[i]
        if  per >= dur
            poi += dur
        else
            poi += per
        end
        i += 1
    end
    poi += dur
end
```
