## Problem 1

### Binary search

```ruby
def judge_square_sum(c)
  size = Math.sqrt(c).to_i

  (0..size).each do |i|
    start = i
    finish = size
    loop do
      j = (start + finish) / 2
      if i * i + j * j < c
        start = j + 1
      elsif i * i + j * j > c
        finish = j - 1
      else
        return true
      end

      if start > finish
        break
      end
    end
  end

  false
end
```

### SQRT

```ruby
def judge_square_sum(c)
  size = Math.sqrt(c).to_i

  (0..size).each do |i|
    start = i
    finish = size
    b = Math.sqrt(c - i * i).to_i

    return true if b * b + i * i == c

  end

  false
end
```
