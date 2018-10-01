# Problem 1
```ruby
# @param {Integer[]} nums
# @return {Integer}
def single_number(nums)
  ret = 0

  nums.each do |num|
    ret ^= num
  end

  ret
end
```

# Problem 2
```ruby
# @param {String} s
# @return {Integer}
def count_substrings(s)
  ret = 0
  0.upto(2*s.length - 1) do |center|
    left = center / 2
    right = left + center % 2
    while left >= 0 && right < s.length && s[left] == s[right]
      ret += 1
      left -= 1
      right += 1
    end
  end
  ret
end
```
