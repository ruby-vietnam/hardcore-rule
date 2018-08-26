# Problem 1: House Robber

https://leetcode.com/problems/house-robber/description/

```
Runtime: 80 ms
Your runtime beats 10.34 % of ruby submissions.
```

```ruby
# @param {Integer[]} nums
# @return {Integer}
def rob(nums)
  maxs = []
  (nums.length - 1).downto(0) do |i|
    if maxs.size > 1
      max1 = maxs[1]
      max2 = maxs[2] || 0
      max = nums[i] + max1 >= nums[i] + max2 ? nums[i] + max1 : nums[i] + max2
    else
      max = nums[i]
    end
    maxs[i % 2] = max
  end
  p maxs
  max1 = maxs[0] || 0
  max2 = maxs[1] || 0
  max1 > max2 ? max1 : max2
end
```

# Problem 2: Word Break

https://leetcode.com/problems/word-break/description/

```
Runtime: 48 ms
Your runtime beats 100.00 % of ruby submissions.
```

```ruby
# @param {String} s
# @param {String[]} word_dict
# @return {Boolean}
def word_break(s, word_dict)
  @found = false
  find_breaks(s, word_dict, '')
  @found
end

def find_breaks(s, word_dict, start)
  return if @found
  word_dict.each do |word|
    if s.start_with?(start + word)
      new_word = start
      ##### Trick testcase #####
      while s.start_with?(new_word + word)
        new_word += word
      end
      ##########################
      if s == new_word
        @found = true
      else
        find_breaks(s, word_dict, new_word)
      end
    end
    return if @found
  end
end
```
