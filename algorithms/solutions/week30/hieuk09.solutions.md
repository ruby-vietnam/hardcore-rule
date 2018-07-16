## Problem 1

```ruby
def miniMaxSum(arr)
  sum = arr.sum
  min = arr.min
  max = arr.max

  puts "#{sum - max} #{sum - min}"
end
```

## Problem 2

```ruby
def matchingStrings(strings, queries)
  hash = Hash.new { 0 }
  hash = strings.inject(hash) do |result, string|
    result[string] += 1
    result
  end

  queries.map { |string| hash[string] }
end
```
