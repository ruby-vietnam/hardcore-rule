
# Problem 1

```ruby
def judge_square_sum(num)
  return true if num.zero?
  srof_num = Math.sqrt(num)
  (1..srof_num).each do |i|
    sof_i = i**2
    return true if (Math.sqrt(num - sof_i) % 1).zero?
  end
  false
end
```
