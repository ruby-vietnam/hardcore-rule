## Problem 1

```ruby
def longest_word(words)
  words.sort! do |word_1, word_2|
    if word_1.size == word_2.size
      word_2 <=> word_1
    else
      word_2.size <=> word_1.size
    end
  end

  result = { '' => [] }

  words.each_with_index do |word, index|
    shorter_word = word.chop

    if words[(index + 1)..(words.size - 1)].include?(shorter_word)
      result[shorter_word] ||= []
      result[shorter_word] << word
    elsif shorter_word == ''
      result[''] << word
    end
  end

  queue = ['']
  max = ''

  while !queue.empty?() do
    element = queue.pop
    list = result[element]

    list && list.each do |new_element|
      if max.size < new_element.size || (max.size == new_element.size && max > new_element)
        max = new_element
      end
      queue.push(new_element)
    end
  end

  max
end
```
