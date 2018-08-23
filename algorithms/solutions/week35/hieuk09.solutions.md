## Problem 2

```ruby
def spiral_matrix_iii(r, c, r0, c0)
  count = 1
  total = r * c
  directions = [
    [0, 1],
    [1, 0],
    [0, -1],
    [-1, 0]
  ]
  direction = 0
  step = 1
  result = [[r0, c0]]
  current_r = r0
  current_c = c0

  while count < total
    delta_r, delta_c = directions[direction]

    step.to_i.times do |i|
      current_r = current_r + delta_r
      current_c = current_c + delta_c

      if current_r < r && current_c < c && current_r >= 0 && current_c >= 0
        result << [current_r, current_c]
        count += 1
      end
    end

    direction = (direction + 1) % 4
    step += 0.5
  end

  result
end
```
