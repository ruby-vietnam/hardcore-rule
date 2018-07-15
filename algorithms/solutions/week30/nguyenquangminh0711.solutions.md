## Problem 1

https://www.hackerrank.com/challenges/mini-max-sum/problem

Well, we only have 6 elements. Just generate the sums and count.

```ruby
def miniMaxSum(arr)
    sums = arr.combination(4).map { |c| c.inject(&:+) }
    puts "#{sums.min} #{sums.max}"
end

arr = gets.rstrip.split(' ').map(&:to_i)

miniMaxSum arr
```

## Other output

https://github.com/zendesk/ruby-kafka/pull/608
