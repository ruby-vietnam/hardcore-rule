## Problem 1

```ruby
def count_and_say(n)
  return '1' if n == 1

  zero_ord = '0'.ord

  (n - 1).times.inject('1') do |acc|
    count = 0
    previous = nil

    acc.each_char.each_with_index.inject('') do |result, (c, index)|
      previous ||= c

      if previous != c
        result << "#{count}#{previous.ord - zero_ord}"
        previous = c
        count = 1
      else
        count += 1
      end

      if index == acc.size - 1
        result << "#{count}#{c.ord - zero_ord}"
      end

      result
    end
  end
end
```
