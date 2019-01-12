## Problem 1

```ruby
def two_sum(numbers, target)
  numbers.each_with_index do |number, i|
    remaining = target - number

    other_index = numbers[(i+1)..numbers.length].bsearch_index { |n| remaining - n }

    if other_index
      return [i+1, i+other_index+2]
    end
  end
end
```
