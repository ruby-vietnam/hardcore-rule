# Problem 1: Count and Say

https://leetcode.com/problems/count-and-say/description/

```
Runtime: 36 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {Integer} n
# @return {String}
def count_and_say(n)
  result = '1'
  (n - 1).times do
    new_result = ''
    count = 0
    char = ''
    result.each_char do |c|
      if char != c
        new_result << count.to_s + char if count > 0
        char = c
        count = 1
      else
        count += 1
      end
    end
    new_result << count.to_s + char if count > 0
    result = new_result
  end
  result
end
```
