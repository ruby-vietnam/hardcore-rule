## Problem 1

```ruby
def get_row(row_index)
  previous = [1]

  (row_index + 1).times do |i|
    if i == 0
      previous
    else
      result = []
      (i - 1).times do |j|
        result << previous[j] + previous[j + 1]
      end
      previous = [1] + result + [1]
    end
  end

  previous
end
```

## Problem 2


