# Problem 1: Pascal's Triangle II
https://leetcode.com/problems/pascals-triangle-ii/description/

Sử dụng công thức để giải quyết bài toán
```ruby
def get_row(row_index)
  result = Array.new(row_index + 1, 1)

  row_index.times do |i|
    result[i + 1] = result[i] * (i + 1) 
  end

  (row_index + 1).times do |i|
    if i <= row_index / 2
      result[i] = result[row_index] / (result[i] * result[row_index - i])
    else
      result[i] = result[row_index - i]
    end
  end
  
  result
end
```

# Problem 2: Valid Parenthesis String
https://leetcode.com/problems/valid-parenthesis-string/description/

So sánh `(` và `)`
```ruby
def check_valid_string(s)
  symbol = { '(' => 0, ')' => 0, '*' => 0 }
  balance = 0
  s.each_char do |c|
    symbol[c] += 1
    balance += 1 if c == '('
    return false if symbol[')'] - symbol['('] > symbol['*']
    balance -= 1 unless c == '(' || balance == 0
  end
  balance == 0 ? true : false
end
```
