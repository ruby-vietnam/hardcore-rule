# Problem 1

```ruby
def find_words(words)
  line1 = %w[q w e r t y u i o p]
  line2 = %w[a s d f g h j k l]
  line3 = %w[z x c v b n m]

  res = []

  words.each do |w|
    (1..3).each do |i|
      if (w.downcase.split('') - line1).empty?
        res << w
        break
      end
      if (w.downcase.split('') - line2).empty?
        res << w
        break
      end
      if (w.downcase.split('') - line3).empty?
        res << w
        break
      end
    end
  end
  res
end
```
