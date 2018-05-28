## Problem 2
https://leetcode.com/problems/simplify-path/

String processing approach

```ruby
# @param {String} path
# @return {String}
def simplify_path(path)
  t = path.split('/').select { |w|
    !w.empty? && w != '.'
  }.reduce('') { |p, word|
    next p + '/' + word unless word == '..'
    rindex = p.rindex('/')
    if rindex.nil?
      p
    elsif rindex.zero?
      ''
    else
      p.slice(0..rindex - 1)
    end
  }
  t.empty? || t.nil? ? '/' : t
end
```
