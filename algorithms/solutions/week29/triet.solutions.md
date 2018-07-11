# Week 29

Problem 1: https://leetcode.com/problems/count-and-say/description/

```ruby
# @param {Integer} n
# @return {String}
def count_and_say(n)
  return '1' if n == 1
  (1..n-1).reduce('1') { |r, _| gen(r)}
end

def gen(input)
  prev = nil 
  count = 0
  input.each_char.reduce('') { |r, c| 
    if c != prev && count != 0
      r = r + count.to_s + prev
      count = 0
    end
    prev = c
    count+=1
    r
  } + count.to_s + prev
end
```
