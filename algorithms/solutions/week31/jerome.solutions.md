## Problem 1 (http://codeforces.com/contest/550/problem/A)
```ruby

s = gets.chomp

n = s.length
l_ab, l_ba, r_ab, r_ba = 0, 0, n - 1, n - 1

while l_ab < n - 1 && r_ba >= 1
  first = s[l_ab] + s[l_ab + 1]
  last = s[r_ba - 1] + s[r_ba]

  if first == "AB"
    break if last == "BA"
    r_ba -= 1
  else
    l_ab += 1
  end
end

while l_ba < n - 1 && r_ab >= 1
  first = s[l_ba] + s[l_ba + 1]
  last = s[r_ab - 1] + s[r_ab]

  if first == "BA"
    break if last == "AB"
    r_ab -= 1
  else
    l_ba += 1
  end
end

puts (r_ba - l_ab - 1 > 1) || (r_ab - l_ba - 1 > 1) ? "YES" : "NO"

```
