# 1. Excel Sheet Column Title

https://leetcode.com/problems/excel-sheet-column-title/

## 1.1. Summary

## 1.2. Code

```rb
@alphabet = ('A'..'Z').to_a
def convert_to_title(column_number)
  return @alphabet[column_number - 1] if column_number <= 26
  
  column_number, offset = column_number.divmod(26)
  if offset == 0
    column_number -= 1
  end
  return convert_to_title(column_number) + @alphabet[offset - 1]
end
```

# 2. Climbing Stairs

https://leetcode.com/problems/climbing-stairs/

## 2.1. Summary

- Using recursive and memoization.

## 2.2. Code

```rb
def climb_stairs(n)
  hash = { 1 => 1, 2 => 2 }
  recursive(n, hash)
end

def recursive(n, hash)
  return hash[n] if hash.include?(n)

  hash[n] = recursive(n-1, hash) + recursive(n-2, hash)
end
```

# 3. House Robber

https://leetcode.com/problems/house-robber/

## 3.1. Summary

- Using recursive and memoization.

## 3.2. Code

```rb
def rob(nums)
  hash = {}
  len = nums.length
  start_from_0 = recursive(0, nums, hash, len)
  start_from_1 = recursive(1, nums, hash, len)
  return start_from_0 > start_from_1 ? start_from_0 : start_from_1
end

def recursive(i, nums, hash, len)
  return 0 if i > len - 1
  return hash[i] if hash.include?(i)

  recursive_2 = recursive(i+2, nums, hash, len)
  recursive_3 = recursive(i+3, nums, hash, len)
  hash[i] = (recursive_2 > recursive_3 ? nums[i] + recursive_2 : nums[i] + recursive_3)
end
```

# 4. House Robber II

https://leetcode.com/problems/house-robber-ii/

## 4.1. Summary

- Like number 3.

## 4.2. Code

```rb
def rob(nums)
  len = nums.length
  return nums[0] if len == 1

  hash = {}
  start_from_0 = recursive(0, nums, hash, len, 0)
  start_from_1 = recursive(1, nums, hash, len, 1)
  start_from_2 = recursive(2, nums, hash, len, 2)
  return [start_from_0, start_from_1, start_from_2].max
end

def recursive(i, nums, hash, len, from)
  puts i
  if ((from == 1 || from == 2) && i > len - 1) || (from == 0 && i > len - 2)
    return 0
  end
  return hash[[from, i]] if hash.include?([from, i])

  recursive_2 = recursive(i+2, nums, hash, len, from)
  recursive_3 = recursive(i+3, nums, hash, len, from)
  hash[[from, i]] = (recursive_2 > recursive_3 ? nums[i] + recursive_2 : nums[i] + recursive_3)
end
```
