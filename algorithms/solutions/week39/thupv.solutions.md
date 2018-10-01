## Problem 1
Link: https://leetcode.com/problems/reverse-integer
 * 1032  / 1032  test cases passed.
 * Status: Accepted

```ruby
# @param {Integer} x
# @return {Integer}
def reverse(x)
  if x != 0 || x.abs > 2147483648
    data = []
    sign = ''
    if x < 0
      sign = '-'
      x = x.abs
    end
    while(x%10 == 0)
      x = x/10  
    end
    while(x>=10)
      data << x%10
      x = (x/10).floor
    end
    data << x if x > 0
    n = (sign + data.join()).to_i
    return n.abs > 2147483648 ? 0 : n
  else
    0
  end
end

```
