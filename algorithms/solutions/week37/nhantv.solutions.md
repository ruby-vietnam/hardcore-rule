# Problem 1: Power of Three

https://leetcode.com/problems/power-of-three/description/

```
Runtime: 160 ms
Your runtime beats 83.78 % of ruby submissions.
```

```ruby
# @param {Integer} n
# @return {Boolean}
def is_power_of_three(n)
  return false if n <= 0
  l = Math.log(n, 3).round
  3 ** l == n
end
```

# Problem 2: Find K Closest Elements

https://leetcode.com/problems/find-k-closest-elements/description/

```
Runtime: 108 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {Integer[]} arr
# @param {Integer} k
# @param {Integer} x
# @return {Integer[]}
def find_closest_elements(arr, k, x)
  len = arr.length - 1
  l = 0
  r = len
  while l < r
    m = ((l + r) / 2.0).ceil
    if arr[m] == x
      l = m
      break
    end
    if arr[m] < x
      l = m
    else
      r = m -1
    end
  end
  return arr[-k..-1] if l == len
  return arr[0..k-1] if l == 0
  i1 = i2 = l
  count = 1
  while count < k
    if i1 == 0
      i2 += 1
    elsif i2 == len
      i1 -= 1
    elsif x - arr[i1 - 1] <= arr[i2 + 1] - x
      i1 -= 1
    else
      i2 += 1
    end
    count += 1
  end
  arr[i1..i2]
end
```
