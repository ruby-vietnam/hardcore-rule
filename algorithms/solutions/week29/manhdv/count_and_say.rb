# https://leetcode.com/problems/count-and-say/description/

def next_term(n)
  term = ''
  char = n[0]
  num_chars = 1

  1.upto(n.size - 1) do |idx|
    next_char = n[idx]
    if next_char == char
      num_chars += 1
    else
      term << num_chars.to_s + char
      char = next_char
      num_chars = 1
    end
  end
  term << num_chars.to_s + char

  term
end

# @param {Integer} n
# @return {String}
def count_and_say(n)
  term = '1' # First term

  (n - 1).times do
    term = next_term(term)
  end

  term
end
