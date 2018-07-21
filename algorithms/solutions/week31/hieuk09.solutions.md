## Problem 1

```ruby
str = gets.chomp

def occurences(str)
  flag = false

  str.each_char.each_with_index.inject([]) do |result, (c, index)|
    if c == 'A'
      flag = true
    elsif c == 'B' && flag
      result << index - 1
      flag = false
    else
      flag = false
    end

    result
  end
end

array = occurences(str)
reverse_array = occurences(str.reverse).map do |item|
  str.size - item - 1
end.sort

result = nil

array.each do |item|
  result = reverse_array.find do |other_item|
    (other_item - item > 2) || (other_item < item)
  end

  if result
    break
  end
end

if result.nil? || array.empty? || reverse_array.empty?
  puts 'NO'
else
  puts 'YES'
end
```
