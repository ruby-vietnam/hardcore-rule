## Problem 1

```ruby
def subdomains_visits(cpdomains)
  hash = Hash.new { |hash, key| hash[key] = 0 }

  cpdomains.each do |cpdomain|
    count, domain = cpdomain.split
    count = count.to_i

    subs = domain.split(".")
    i = subs.length - 1
    current_sub = subs[i]
    while i >= 0
      hash[current_sub] += count
      i -= 1
      current_sub = subs[i] + "." + current_sub
    end
  end

  result = []
  for k, v in hash
    result << [v, k].join(" ")
  end

  result
end

```

## Problem 2

```ruby
def opposite?(a, b)
  (a == "NORTH" && b == "SOUTH") || (a == "SOUTH" && b == "NORTH") || (a == "WEST" && b == "EAST") || (a == "EAST" && b == "WEST")
end

def dir_reduce(list)
  result = []

  i = 0
  while i < list.length
    if opposite?(list[i], list[i + 1])
      i += 2
      next
    else
      opposite?(result[-1], list[i]) ? result.pop : result << list[i]
      i += 1
    end
  end

  result
end

```

## Problem 4

```ruby
def prime?(n)
  return true if n == 1

  i = 2
  while i <= Math.sqrt(n)
    if n % i == 0
      return false
    end
    i += 1
  end

  true
end

def find_all_prime(n)
  n = n < 0 ? -n : n

  if prime?(n)
    return [n]
  end

  result = []

  i = 2
  while i <= n / 2
    if prime?(i) && n % i == 0
      result << i
    end
    i += 1
  end
  result
end

def sumOfDivided(list)
  result = []
  hash = Hash.new { |hash, key| hash[key] = 0 }

  for num in list
    primes = find_all_prime(num)
    for p in primes
      hash[p] += num
    end
  end

  for k in hash.keys.sort
    result << [k, hash[k]]
  end

  result
end

```
