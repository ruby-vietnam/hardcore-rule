## Problem 1

https://leetcode.com/problems/climbing-stairs/description/

Classic Fibonaci problem. Calculate the nth fibonaci.

```ruby
# @param {Integer} n
# @return {Integer}
def climb_stairs(n)
    n_1 = 1
    return n_1 if n == 1
    n_2 = 2
    return n_2 if n == 2
    n_n = n_1 + n_2
    (3..n).each do
        n_n = n_1 + n_2
        n_1 = n_2
        n_2 = n_n
    end
    n_n
end
```
