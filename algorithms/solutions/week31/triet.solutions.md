## Problem 1

```ruby
input = gets.chomp

def val(input)
  ab_index = []
  ba_index = []
  i = 0
  while i < input.length - 1
    ab_index << i if input[i..i + 1] == 'AB'
    i += 1
  end

  i = input.length - 1
  while i >= 0
    ba_index << i if input[i..i + 1] == 'BA'
    i -= 1
  end

  if !ba_index.first.nil? &&
     !ab_index.first.nil? &&
     (ba_index.first - ab_index.first > 1 ||
      ab_index.last - ba_index.last > 1)
    puts 'YES'
    return
  end

  puts 'NO'
end

val(input)
```
