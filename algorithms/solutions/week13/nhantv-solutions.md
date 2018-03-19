# Problem 1: Maximum Product of Three Numbers

https://leetcode.com/problems/maximum-product-of-three-numbers/description/

```
Runtime: 80 ms
Your runtime beats 90.00 % of ruby submissions.
```

```ruby
# @param {Integer[]} nums
# @return {Integer}
def maximum_product(nums)
  nums.sort!
  sum1 = nums[0] * nums[1] * nums[-1]
  sum2 = nums[-1] * nums[-2] * nums[-3]
  sum1 > sum2 ? sum1 : sum2
end
```

# Problem 2: Divide Two Integers

https://leetcode.com/problems/divide-two-integers/description/

```
Runtime: 84 ms
Your runtime beats 0.00 % of ruby submissions. T_T
```

```ruby
# @param {Integer} dividend
# @param {Integer} divisor
# @return {Integer}
def divide(dividend, divisor)
    result = 0
    negative_flag = false
    if(dividend < 0)
        dividend = -dividend
        negative_flag = !negative_flag
    end
    if(divisor < 0)
        divisor = -divisor
        negative_flag = !negative_flag
    end
    if(divisor == 1)
        result = dividend
    else
        while(dividend >= divisor)
            bit = 1
            while(dividend >= divisor<<bit)
                bit += 1
            end
            result += 2**(bit-1)
            dividend -= divisor<<(bit -1)
        end
    end
    if(negative_flag)
        -result
    else
        if(result > 2147483647)
            2147483647
        else
            result
        end
    end
end
```

# Problem 3: Valid Number

https://leetcode.com/problems/valid-number/description/

```
1416 / 1481 test cases passed.
```

```ruby
# @param {String} s
# @return {Boolean}
def is_number(s)
  s.strip!
  return false if s == '' || s.include?(' ') || s == '.' || s[0] == 'e' || s == '-'
  return false unless s.match? /[0-9]/
  s.slice!(0) if s[0] == '-' || s[0] == '+'
  index1 = s.index('.')
  num1 = ''
  if index1
    num1 = s[0...index1]
    s.slice! num1 + '.'
  end
  index2 = s.index('e')
  num2 = ''
  if index2
    num2 = s[0...index2]
    s.slice! num2 + 'e'
  end
  if num1.size > 0
    return false unless num1.match? /^[0-9]+$/
  end
  if num2.size > 0
    return false unless num2.match? /^[0-9]+$/
  end
  if s.size > 0
    return false  unless s.match? /^[0-9]+$/
  end
  true
end
```


