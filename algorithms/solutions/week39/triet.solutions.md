## Problem 1

```ruby
# @param {Integer} x
# @return {Integer}
def reverse(x)
  max_int = (1 << 31) - 1
  min_int = -1 << 31
  neg = x < 0 ? -1 : 1
  rev = x.abs.to_s.each_char.reduce { |i, r| r << i }.to_i * neg
  rev = 0 if rev > max_int || rev < min_int
  rev
end
```

## Problem 2

```ruby
# @param {Character[][]} board
# @param {String} word
# @return {Boolean}
def exist(board, word)
  @board = board
  @word = word
  
  return false if word.empty?
  board.each.with_index do |row, i_r|
    row.each.with_index do |cell, i_c| 
      if cell == word[0]
        marker_board = Array.new(board.length){Array.new(row.length)}
        return true if check(marker_board, 0, i_r, i_c)
      end
    end
  end
  
  false
end

def check(marker_board, cwi, i_r, i_c)
  return true if cwi >= @word.length
  return false if i_r < 0 || i_c < 0 ||
    i_r >= marker_board.length || i_c >= marker_board[0].length ||
    !marker_board[i_r][i_c].nil? ||
    @board[i_r][i_c] != @word[cwi]
  
  
  marker_board[i_r][i_c] = 'c'
  ways = [
    {r: 0, c: -1}, # left
    {r: 0, c: 1}, # right
    {r: -1, c: 0}, # down
    {r: 1, c: 0} # up
    ]
  ways.each { |w|
    return true if check(marker_board, cwi + 1, i_r + w[:r], i_c + w[:c])
  }
  marker_board[i_r][i_c] = nil
  false
end
```
