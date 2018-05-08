# Problem 1

```ruby
def plus_one(arr)
  i = arr.size - 1
  while i >= 0
    if i.zero? && arr[i] == 9
      arr[i] = 0
      return [1].concat(arr)
    elsif arr[i] != 9
      arr[i] = arr[i] + 1
      break
    else
      arr[i] = 0
    end
    i -= 1
  end
  arr
end
```
