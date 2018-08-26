## Problem 1

K-based Numbers: http://acm.timus.ru/problem.aspx?space=1&num=1009

### Solution 1: Using DP, bottom up

Time: O(n)
Space: O(1)

```ruby
def find_qty_of_numbers2(n, k)
  n == 0 && (return 0)
  n == 1 && (return k)
  x = 1
  y = k - 1
  c = 0
  (0...n - 1).each do |i|
    c = (k - 1) * (x + y);
    x = y
    y = c
  end

  c
end
```

### Solution 2: Using multiplication & addition principle, recursion, top down

Slower than Solution 1 due to the growth of callstack when `n` grows
Time: O(n)
Space: O(1)

#### Example
`n = 5`
`k = 10`

Number format: `abcde`

Break down:

```
a > 0 => a: k-1 = 9
b:

- b = 0 => b: 1
  - c > 0 => c: 9
    - d = 0 => d: 1
      - e > 0 => e: 9
    - d > 0 => d: 9
      - e >= 0 => e: k = 10
- b > 0 => b: 9
  - c = 0 => c: 1
    - d > 0 => d: 9
      - e >= 0 => e: 10
  - c > 0 => c: 9
    - d = 0 => d: 1
      - e > 0 => e: 9
    - d > 0 => d: 9
      - e >= 0 => e: 10

numbers = 9 * (
  (1 * 9 * (
      1*9 +
      9*10
    )
  ) +
  (9 * (
      1*9*10 +
      9* (
        1*9 +
        9*10
      )
    )
  )
)
```

#### Implementation

```ruby
def find_qty_of_numbers3(n, k)
  n === 0 && (return 0)
  n === 1 && (return k)
  (k - 1) * count(n - 1, k, false)
end

def count(i, k, prevIsZero)
  i === 0 && (return 0)
  if (prevIsZero)
    i === 1 ? k - 1 : (k - 1) * count(i - 1, k, false)
  else
    i === 1 ? k : (count(i - 1, k, true) + (k - 1) * count(i - 1, k, false))
  end
end
```
