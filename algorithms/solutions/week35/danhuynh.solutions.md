# Problem 1
```ruby
def solve(n, k)
  zero_count = 0
  count = k - 1
  (n-1).times do
    new_zero_count = count - zero_count
    # each number that do not end with zero in A[n - 1] will be prefix of k numbers in A[n]
    # each number that end with zero in A[n - 1] will be prefix of k - 1
    # (exclude 0 because 2 successive 2 is invalid) numbers in A[n]
    count = (count - zero_count) * k + zero_count * (k - 1)
    zero_count = new_zero_count
  end
  p count
end

n = gets.strip.to_i
k = gets.strip.to_i

solve(n, k)
```
