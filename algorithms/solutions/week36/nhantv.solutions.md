# Problem 1: Climbing Stairs

https://leetcode.com/problems/climbing-stairs/description/

```
Runtime: 44 ms
Your runtime beats 84.21 % of ruby submissions.
```

```ruby
# @param {Integer} n
# @return {Integer}
def climb_stairs(n)
  return 1 if n <= 1
  return 2 if n == 2
  a = 1
  b = 2
  result = 0
  (n - 2).times do
    result = a + b
    a = b
    b = result
  end
  result
end
```

# Problem 2: Longest Substring Without Repeating Characters

https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

```
Runtime: 198 ms
Your runtime beats 36.36 % of ruby submissions.
```

```ruby
# @param {String} s
# @return {Integer}
def length_of_longest_substring(s)
    max = 0
    sub = []
    s.each_char do |c|
        sub.each.with_index do |sc, index|
            if sc == c
                sub_len = sub.length
                max = sub_len if max < sub_len
                sub = sub.drop(index + 1)
                flag = true
                break
            end
        end
        sub.push(c)
    end
    sub_len = sub.length
    max = sub_len if max < sub_len
    max
end
```
