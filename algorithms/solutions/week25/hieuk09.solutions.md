## Problem 1

```ruby
LINE_1 = %w(q w e r t y u i o p)
LINE_2 = %w(a s d f g h j k l)
LINE_3 = %w(z x c v b n m)
ALL_LINES = [LINE_1, LINE_2, LINE_3]

def find_words(words)
  words.select do |word|
    ALL_LINES.any? do |line|
      word.downcase.each_char.all? do |c|
        line.include?(c)
      end
    end
  end
end
```
