# Week 35

## Problem 2 

Medium: https://leetcode.com/contest/weekly-contest-97/problems/spiral-matrix-iii/

```ruby
# @param {Integer} r
# @param {Integer} c
# @param {Integer} r0
# @param {Integer} c0
# @return {Integer[][]}
def spiral_matrix_iii(r, c, r0, c0)
  result = [[r0, c0]]
  directions = [0,1,0,-1,0]
  step, direction_sup = 0, 0
  until result.size == r*c do
    step += 1
    (0..1).each do |_|
      cur_step = step
      until cur_step == 0 do
        r0 += directions[direction_sup]
        c0 += directions[direction_sup+1]
        cur_step -= 1
        next if r0 < 0 || r0 >= r || c0 < 0 || c0 >= c
        result << [r0, c0]
      end
      direction_sup = (direction_sup + 1) % 4
    end
  end
  return result
end
```

> Submission Detail
73 / 73 test cases passed.
Status: Accepted
Runtime: 156 ms
Submitted: 0 minutes ago
