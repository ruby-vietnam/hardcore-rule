## Problem 1
Link: https://leetcode.com/problems/climbing-stairs
 * 45 / 45 test cases passed.
 * Status: Accepted

```ruby
#a(n) = a(n-1) + a(n-2)
def climb_stairs(n)
   res = []
   res << 1
   res << 2
   (2..n-1).each do |i|
     res[i] = res[i-1] + res[i-2]
   end
   res[n-1]
end
```
