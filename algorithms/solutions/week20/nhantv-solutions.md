# Problem 1: Plus One

https://leetcode.com/problems/plus-one/description/

```
Runtime: 36 ms
Your runtime beats 98.36 % of ruby submissions.
```

```ruby
# @param {Integer[]} digits
# @return {Integer[]}
def plus_one(digits)
  index = digits.size - 1
  while digits[index] == 9
    digits[index] = 0
    index -= 1
  end
  if index >= 0
    digits[index] += 1
  else
    digits = [1] + digits
  end
  digits
end
```

# Problem 2: String to Integer (atoi)

https://leetcode.com/problems/string-to-integer-atoi/description/

```
Runtime: 48 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {String} str
# @return {Integer}
def my_atoi(str)
  str.strip!
  negative = str[0] == '-' ? true : false
  str[0] = '' if negative || str[0] == '+'
  int = 0
  str.each_char do |char|
    if char =~ /[0-9]/
      int = int * 10 + char.ord - 48
    else
      break
    end
  end
  int *= -1 if negative
  int = -2**31 if int < -2**31
  int = 2**31 - 1 if int >= 2**31
  int
end
```

# Problem bonus: Word Break II

https://leetcode.com/problems/word-break-ii/description/

```
Time Limit Exceeded
31 / 39 test cases passed.
```

```ruby
# @param {String} s
# @param {String[]} word_dict
# @return {String[]}
class Word
  attr_accessor :list
  def initialize(words)
    @list = words
  end
end

def word_break(s, word_dict)
  result = []
  word_dict.each.with_index do |word, index|
    if s.start_with?(word)
      if word == s
        result.push(word)
      else
        words = Word.new([word])
        find_children(words, s, word_dict, result)
      end
    end
  end
  result.uniq
end

def find_children(words, s, word_dict, result)
  word_dict.each.with_index do |word, index|
    if s.start_with?(words.list.join + word)
      new_word = Word.new(words.list + [word])
      if new_word.list.join == s
        result.push(new_word.list.join(' '))
      else
        find_children(new_word, s, word_dict, result)
      end
    end
  end
end
```
