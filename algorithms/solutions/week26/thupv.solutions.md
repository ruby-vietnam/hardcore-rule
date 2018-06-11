## Problem 1
Link: https://leetcode.com/problems/find-the-difference

 * 54 / 54 test cases passed.
 * Status: Accepted
 * Runtime: 64 ms
 
```ruby
# @param {String} s
# @param {String} t
# @return {Character}
def find_the_difference(s, t)
  hash = {}
  for i in 0..s.length-1 do
    hash[s[i]] = hash[s[i]].nil? ? 1 : hash[s[i]] + 1
  end
  for i in 0..t.length-1 do
    return t[i] if hash[t[i]].nil? || hash[t[i]] == 0
    hash[t[i]] = hash[t[i]] - 1
  end
end
```
