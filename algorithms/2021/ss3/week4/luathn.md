# 1. Two Sum

https://leetcode.com/problems/two-sum/

### Approach - Hash

### Submission

```rb
def two_sum(nums, target)
  hash = {}
  nums.each_with_index do |num, index|
    offset = target - num
    return [hash[offset], index] if hash.include?(offset)
    hash[num] = index
  end
end
```

# 20. Valid Parentheses

https://leetcode.com/problems/valid-parentheses/

### Approach - Stack

### Submission

```rb
def is_valid(s)
  brackets_hash = { "(" => ")", "[" => "]", "{" => "}" }
  stack = []
  s.each_char do |c|
    if brackets_hash.keys.include?(c)
      stack.push(c)
    else
      return false if brackets_hash[stack.pop] != c
    end
  end
  stack.empty?
end
```

# 22. Generate Parentheses

https://leetcode.com/problems/generate-parentheses/

### Submission - Need to improve complexity

```rb
def generate_parenthesis(n)
  hash = {}
  if n == 1
    hash["()"] = 1
    return ["()"]
  end
  arr_of_str = generate_parenthesis(n - 1)
  arr_of_str.each do |str|
    str.each_char.with_index do |c, index|
      new = str[0..index] + "()" + str[(index+1)..]
      if !hash.include?(new)
        hash[new] = 1
      end
    end
  end
  hash.keys
end
```
