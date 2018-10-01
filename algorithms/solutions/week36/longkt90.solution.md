# Problem 1 : Climbing Stairs

URL: https://leetcode.com/problems/climbing-stairs/description/

```ruby
def permutation(number)
  result = 1
  (2..number).each { |num| result *= num }
  result
end

def combination(n, k)
  return 1 if k.zero? || n == k
  permutation(n) / (permutation(k) * permutation(n - k))
end

def climb_stairs(n)
  return n if n == 1
  max_two = n / 2
  count = 0
  (0..max_two).each do |number_of_two|
    count += combination(n - number_of_two, number_of_two)
  end
  count
end
```
