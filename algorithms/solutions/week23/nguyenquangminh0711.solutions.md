## Problem 1

https://leetcode.com/problems/simplify-path/description/

Split the original path by `/` character. Loop from each section, ignore if it is `''` or `'.'`. If it is `..`, pop it out of stack. Otherwise, add to the stack.

```ruby
# @param {String} path
# @return {String}
def simplify_path(path)
    return '' if path.empty?
    
    stack = []
    sections = path.split('/')
    sections.each do |section|
        next if section == '' || section == '.'
        if section == '..'
            stack.pop
        else
            stack.push(section)
        end
    end
    if stack.empty?
        '/'
    else
        "/#{stack.join('/')}"
    end
end
```
