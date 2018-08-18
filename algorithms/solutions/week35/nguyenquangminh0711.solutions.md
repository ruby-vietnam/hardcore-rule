## Problem 1

https://leetcode.com/contest/weekly-contest-97/problems/spiral-matrix-iii/

Just a simple loop. Let's use a "phase" concept. There are 4 phases: right, down, left, up. Each each phase, follow the direction for "length" times. When phase % 2 == 0, increase the length. Loop until we reach all the cells

```ruby
DELTA_R = [0, 1, 0, -1]
DELTA_C = [1, 0, -1, 0]

def spiral_matrix_iii(r, c, ri, ci)
    count = r * c - 1
    phase = 0
    steps = [[ri, ci]]
    length = 1
    
    while count > 0
        length.times do
            ri = ri + DELTA_R[phase]
            ci = ci + DELTA_C[phase]
            if ri >= 0 && ri < r && ci >= 0 && ci < c
                steps << [ri, ci]
                count -= 1
            end
        end
        phase = (phase + 1) % 4
        length += 1 if phase % 2 == 0
    end
    
    steps
end
```

## Problem 3

https://leetcode.com/contest/weekly-contest-97/problems/possible-bipartition/

Classic bipartie graph. 
- We don't care about people that don't have any relationships.
- 1) Let X = {1}. Find Y = all the dislikes of X. If X & Y not empty, we can't arrange the tables.
- 2) Find T = all dislikes of Y. If Y & T not empty, we can't arrange the tables. If T == X, finish.
- 3) Assign X = T, and back to step 1.

```ruby
# @param {Integer} n
# @param {Integer[][]} dislikes
# @return {Boolean}
def possible_bipartition(n, dislikes)
    dislikes_hash = {}
    dislikes.each do |a, b|
        dislikes_hash[a] ||= []
        dislikes_hash[a] << b
        dislikes_hash[b] ||= []
        dislikes_hash[b] << a
    end
    
    x = Set.new
    x.add(1)
    
    while true
        y = find_dislikes_set(x, dislikes_hash)
        return false unless (x & y).empty?
        t = find_dislikes_set(y, dislikes_hash)
        return false unless (t & y).empty?
        return true if t == x
        x = t
    end
end

def find_dislikes_set(x, dislikes_hash)
    y = Set.new
    x.each do |person|
        next if dislikes_hash[person].nil?
        dislikes_hash[person].each do |other|
            y.add(other)
        end
    end
    y
end```
