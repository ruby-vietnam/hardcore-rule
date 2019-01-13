# Problem 1

```ruby
# @param {Integer[]} numbers
# @param {Integer} target
# @return {Integer[]}
def two_sum(numbers, target)
  l = numbers.length - 1
  for i in 0..l
    for j in i+1..l
      return [i+1, j+1] if numbers[i] + numbers[j] == target
      break if numbers[i] + numbers[j] > target
    end
  end
end
```

```ruby
# @param {Integer[]} numbers
# @param {Integer} target
# @return {Integer[]}
def two_sum(numbers, target)
  i = 0
  j = numbers.length - 1
  while i < j
    if numbers[i] + numbers[j] > target
      j -= 1
    elsif numbers[i] + numbers[j] < target
      i += 1
    else
      return [i+1, j+1]
    end
  end
end
```
