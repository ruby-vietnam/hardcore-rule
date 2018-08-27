# Problem 2: Spiral Matrix III

https://leetcode.com/contest/weekly-contest-97/problems/spiral-matrix-iii/

```
Runtime: 160 ms
Your runtime beats 57.14 % of ruby submissions.
```

```ruby
# @param {Integer} r
# @param {Integer} c
# @param {Integer} r0
# @param {Integer} c0
# @return {Integer[][]}
def spiral_matrix_iii(r, c, r0, c0)
  result = [[r0, c0]]
  x = 0
  y = 1
  n = 0
  i = 0
  while result.length < r * c do
    r0 += x
    c0 += y
    i += 1
    if 0 <= r0 && r0 < r && 0 <= c0 && c0 < c
      result << [r0, c0]
    end
    if i == n / 2 + 1
      x, y = y, -x
      n += 1
      i = 0
    end
  end
  result
end

```
