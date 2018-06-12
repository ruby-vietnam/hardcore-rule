# https://leetcode.com/problems/keyboard-row/description/

def build_chars_rows
  chars_in_rows = {}
  first_row = 'qwertyuiopQWERTYUIOP'
  second_row = 'asdfghjklASDFGHJKL'
  third_row = 'zxcvbnmZXCVBNM'

  [first_row, second_row, third_row].each_with_index do |chars, row_idx|
    0.upto(chars.size - 1) do |char_idx|
      chars_in_rows[chars[char_idx]] = row_idx
    end
  end

  chars_in_rows
end

# @param {String[]} words
# @return {String[]}
def find_words(words)
  chars_in_rows = build_chars_rows

  words.select do |word|
    is_all_chars_same_row = true
    row_idx = chars_in_rows[word[0]]

    0.upto(word.size - 1) do |char_idx|
      is_all_chars_same_row &&= chars_in_rows[word[char_idx]] == row_idx
    end

    is_all_chars_same_row
  end
end
