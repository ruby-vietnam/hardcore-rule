## Problem 1
https://leetcode.com/problems/keyboard-row/

```ruby
# @param {String[]} words
# @return {String[]}

def find_words(words)
  words.select { |word| validate_word(word.downcase) }
end

KEYBOARD = [
  %w(q w e r t y u i o p),
  %w(a s d f g h j k l),
  %w(z x c v b n m),
]
def validate_word(word)
  i = 0
  while !KEYBOARD[i].include? (word[0]) 
      i += 1
      return false if i > 2
  end
  
  word.each_char { |c| return false if !KEYBOARD[i].include? (c) }
  true
end
```
