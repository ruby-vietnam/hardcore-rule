## Problem 1

### Loop approach

```ruby
def is_power_of_four(num)
  return false if num == 0

  while (num % 4 == 0) do
    num /= 4
  end

  num == 1
end
```

### Non-loop approach

Because:

```
1(dec) = 1(bin)
4(dec) = 100(bin)
16(dec) = 10000(bin)
64(dec) = 1000000(bin)
```

We observe that:

1) num must have 1 as the most significant bit, other bit must be 0

We have

```
1 & 0 = 0
100 && 011 = 0
10000 && 01111 = 0
```

And

```
0 = 1 - 1
011 = 100 - 1
01111 = 10000 - 1
```

So `num * (num - 1)` must be 0

2) the significant bit must be in position 0, 2, 4, ...

We see that:

```
100 & 10101 = 100
10000 & 10101 = 10000
```

For a 32-bit number, we can check the bit using:

```
1010101010101010101010101010101
```

This number can be present as `0x55555555`. So `num & 0x55555555` must be `num`.

3) this number must not be 0

**Solution**

```ruby
(num & (num - 1)) == 0 && (num & 0x55555555) == num && num != 0
```

## Problem 2

```ruby
def num_islands(grid)
  already_check = {}
  possible_islands = []
  height = grid.size
  width = height > 0 ? grid.first.size : 0
  directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]

  grid.each_with_index do |line, y|
    line.each_with_index do |cell, x|
      if cell == 1
        possible_islands << [x, y]
      end
    end
  end

  count = 1

  while !possible_islands.empty?
    coordinations = possible_islands.pop

    next if already_check[coordinations]

    queue = [coordinations]

    while !queue.empty?
      x, y = pos = queue.pop

      next if already_check[pos]

      already_check[pos] = count

      directions.each do |delta_x, delta_y|
        new_x = x + delta_x
        new_y = y + delta_y

        next if new_x < 0 || new_y < 0 || new_x >= width || new_y >= height
        next if grid[new_y][new_x] != 1

        queue.push([new_x, new_y])
      end
    end

    count += 1
  end

  count - 1
end
```
