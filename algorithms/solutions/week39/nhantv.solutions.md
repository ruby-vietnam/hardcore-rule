Problem 1: Reverse Integer

https://leetcode.com/problems/reverse-integer/description/

```
Runtime: 52 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {Integer} x
# @return {Integer}
def reverse(x)
  sign = x < 0 ? -1 : 1
  x = x.to_i.to_s.reverse.to_i * sign
  (-2 ** 31) > x || (2 ** 31 - 1) < x ? 0 : x
end
```
