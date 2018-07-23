# Problem 1

```ruby
str = gets.chomp

i = 0
n = str.length
met = { first: 0, second: 0 }

while i < n - 1
  if str[i] == 'A' && str[i + 1] == 'B' && met[:first].zero?
    met[:first] = 1
    i += 2
  elsif str[i] == 'B' && str[i + 1] == 'A' && met[:second].zero?
    i += 2
    met[:second] = 1
  end
  i += 1
end

if (met[:first] + met[:second]) == 2
  puts 'YES'
else
  puts 'NO'
end
```
