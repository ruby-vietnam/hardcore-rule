## Problem 1
```ruby
strings = gets.strip

def solve(strings)
  i = 0
  while i < strings.size
    if strings[i..i+1] == 'AB'
      i += 2
      while i < strings.size
        if strings[i..i+1] == 'BA'
          puts 'YES'
          return
        end
        i += 1
      end
    end
    i += 1
  end
  i = 0
  while i < strings.size
    if strings[i..i+1] == 'BA'
      i += 2
      while i < strings.size
        if strings[i..i+1] == 'AB'
          puts 'YES'
          return
        end
        i += 1
      end
    end
    i += 1
  end
  puts 'NO'
end

solve(strings)
```
