## Problem 1

https://leetcode.com/problems/find-the-difference/description/

```ruby
# @param {String} s
# @param {String} t
# @return {Character}
def find_the_difference(s, t)
    hash = {}
    s.chars.each do |c|
        hash[c] ||= 0
        hash[c] += 1
    end
    t.chars.each do |c|
        if hash[c].nil?
            return c
        end
        hash[c] -= 1
    end
    hash.keys.find do |key|
        hash[key] != 0
    end
end
```
