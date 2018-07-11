# Problem 1
```ruby
def count_and_say(n)
  return "1" if n == 1
  str = count_and_say(n - 1)
  result = ""
  i = 0
  while i < str.length
    current = str[i]
    count = 1
    j = i + 1

    while j < str.length
      break if current != str[j]
      count += 1
      j += 1
    end

    result << "#{count}#{current}"
    i = j
  end

  result
end
```
