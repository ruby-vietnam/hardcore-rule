
Link: https://leetcode.com/problems/sum-of-square-numbers

 * 124 / 124 test cases passed.
 * Status: Accepted
 * Runtime: 108 ms


```ruby
# @param {Integer} c
# @return {Boolean}
def judge_square_sum(c)
  return true if c == 0
  sqrt_c = Math.sqrt(c)
  x = 0;
  while x < sqrt_c do
    y = Math.sqrt(c - x * x)
    return true if y.floor == y
    x = x + 1
  end
  return false
end
```