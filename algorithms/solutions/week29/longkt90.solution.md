# Problemm 1: Count and Say

URL: https://leetcode.com/problems/count-and-say/description/

Status:
```
  ✔ Accepted
```
Codes:
```ruby
def count_and_say(n)
  string = '1'
  (n - 1).times do
    string = count_and_say_string(string)
  end
  string
end

def count_and_say_string(string)
  count = 1
  new_string = ''
  i = 0
  while i < string.size
    if string[i + 1] == string[i]
      count += 1
    else
      new_string << "#{count}#{string[i]}"
      count = 1
    end
    i += 1
  end
  new_string
end

```
