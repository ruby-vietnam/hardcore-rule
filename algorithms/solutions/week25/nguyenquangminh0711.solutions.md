## Problem 1

https://leetcode.com/problems/keyboard-row/description/

```ruby
# @param {String[]} words
# @return {String[]}
DATA = [
    %w(q w e r t y u i o p),
    %w(a s d f g h j k l),
    %w(z x c v b n m)
]

def find_words(words)
    lookup_hash = {}
    DATA.each_with_index do |row, index|
        row.each do |char|
            lookup_hash[char] = index
            lookup_hash[char.upcase] = index
        end
    end   
    
    words.select do |word|
        result = true
        chars = word.split('')
        first_row = lookup_hash[chars[0]]
        chars.each do |char|
            if first_row != lookup_hash[char]
                result = false
                break
            end
        end
        result
    end
end
```
