
Link: https://leetcode.com/problems/keyboard-row/description/

 * 22 / 22 test cases passed.
 * Status: Accepted
 * Runtime: 36 ms


```ruby
def find_words(words)
  key_boards = [
    '1234567890',
    'qwertyuiop',
    'asdfghjkl',
    'zxcvbnm']
  map_key = {}
  key_boards.each_with_index do |key_line, i|
    key_line.split("").each do |c|
      map_key[c] = i
    end
  end
  out = []
  words.each do |word|
    word_array = word.downcase.split("")
    prev_key = map_key[word_array[0]]
    catch :deep_error do
      word_array.each do |c|
        throw :deep_error if map_key[c] != prev_key
      end
      out << word
    end
  end
  out
end
```