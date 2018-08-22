## Problem 1

Brute force TLE

```ruby
@count = 0

def kbase(n, k)
  k -= 1 if k > 1
  generate(n, k, '')
end

def generate(n, k, f)
  return if !f.empty? && f[0] == '0'

  if f.length >= n
    return if f.length > n

    @count += 1 if validate(f)
    return
  end

  (0..k).each do |digit|
    generate(n, k, f + digit.to_s)
  end
end

def validate(f)
  i = 1
  until i == f.length
    if f[i] == '0' && f[i - 1] == '0'
      puts f
      return false
    end
    i += 1
  end

  true
end

n = gets.chomp.to_i
k = gets.chomp.to_i

kbase(n, k)

puts @count
```

DP

```ruby
def kbase(n, k)
  # fn = (k-1)fn-1 + fn-2(k-1)

  i = 2
  fn2 = (k-1)
  fn1 = (k-1)*fn2
  while i < n do
    fn = (k - 1) * fn1 + (k - 1) * fn2
    fn2 = fn1
    fn1 = fn
    i = i + 1
  end

  puts fn1 + fn2
end

n = gets.chomp.to_i
k = gets.chomp.to_i

kbase(n, k)
```
