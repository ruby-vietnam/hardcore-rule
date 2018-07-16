## Problem 1 - [Mini-Max Sum](https://www.hackerrank.com/challenges/mini-max-sum/problem)

```ruby

arr = gets.chomp.split.map(&:to_i)

min, max, sum = arr[0], arr[0], 0

for num in arr
  sum += num
  min = num if num < min
  max = num if num > max
end

print sum - max, " ", sum - min

```

## Problem 2 - [Sparse Arrays](https://www.hackerrank.com/challenges/sparse-arrays/problem)

```ruby

n = gets.chomp.to_i
hash = Hash.new { |hash, key| hash[key] = 0 }

n.times do |i|
  str = gets.chomp
  hash[str] += 1
end

q = gets.chomp.to_i
queries = []

q.times do |i|
  queries[i] = gets.chomp
end

result = []
for q in queries
  result << hash[q]
end

puts result

```
