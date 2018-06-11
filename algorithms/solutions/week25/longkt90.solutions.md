### Prolem 1 - [500. Keyboard Row](https://leetcode.com/problems/keyboard-row/description/)

Status:
```
  ✔ Accepted
```

```ruby
# @param {String[]} words
# @return {String[]}
def find_row(character)
  case character
  when *%w[z x c v b n m Z X C V B N M]
    1
  when *%w[q w e r t y u i o p Q W E R T Y U I O P]
    2
  when *%w[a s d f g h j k l A S D F G H J K L]
    3
  end
end

def find_words(words)
  row = nil
  words.keep_if do |word|
    row = find_row(word[0])
    word[1..-1]
    word[1..-1].each_char.none? { |char| p find_row(char) != row }
  end
end
```
