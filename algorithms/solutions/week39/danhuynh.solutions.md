# Problem 1
```ruby
# @param {Integer} x
# @return {Integer}
def reverse(x)
  ret = if x < 0
    -x.to_s[1..-1].reverse.to_i
  else
    x.to_s.reverse.to_i
  end

  return 0 if ret >= 2 ** 31 || ret < -2 ** 31
  return ret
end
```
