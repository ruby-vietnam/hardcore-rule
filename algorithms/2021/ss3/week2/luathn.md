# 1. Happy Number

https://leetcode.com/problems/happy-number/

## 1.1. Summary

- Using an array to store all numbers just check is_happy. Try to use hash but array a little bit faster, I think because this array stores just a few numbers.
- Split number and calculate square, check if it is happy, store to the array. If not, just loop this step until arr includes number, so this number is not happy, lol.

## 1.2. Code

```rb
def is_happy(number)
  arr = []
  while !arr.include?(number)
    arr << number
    number = number.digits.sum {|x| x**2}
    return true if number == 1
  end
  false
end
```

# 2. Longest Happy String

https://leetcode.com/problems/longest-happy-string/

## 2.1. Summary

- Using a multidimensional array to store character and number of rest characters.
- Sort array DESC.
- Find the next character to add to the final string.
- Add to string, decrease the number of rest characters in store.
- Loop until can not find next char.

## 2.2. Code

```rb
def longest_diverse_string(a, b, c)
  arr = [[a, "a"], [b, "b"], [c, "c"]]
  str = ""
  while true
    arr = arr.sort.reverse
    next_char_index = find_next_char_index(arr, str)
    break if next_char_index.nil?
    add_char(arr, str, next_char_index)
  end
  return str
end

def find_next_char_index(arr, str)
  length = str.length
  if length > 1 && arr[0][1] == str[length-1] && arr[0][1] == str[length-2]
    return nil if arr[1][0] == 0
    return 1
  else
    return nil if arr[0][0] == 0
    return 0
  end
end

def add_char(arr, str, index)
  next_char = arr[index][1]
  str << next_char
  arr[index][0] -= 1
end
```
