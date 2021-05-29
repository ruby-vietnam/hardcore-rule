## 67. Add Binary

https://leetcode.com/problems/add-binary/

### If-else, simulation

Complexity: `O(max(M,N))`

```
Runtime: 68 ms, faster than 21.38% of Ruby online submissions for Add Binary.
Memory Usage: 210.2 MB, less than 15.17% of Ruby online submissions for Add Binary.
```

```ruby
# @param {String} a
# @param {String} b
# @return {String}
def add_binary(a, b)
  n = a.length
  m = b.length
  mm = [m,n].max
  res = ''
  rem = '0'
  
  # pp "n=#{n}, m=#{n}, mm=#{mm}"
  
  for i in (-1).downto(-mm - 1)
    va = a[i] || '0'
    vb = b[i] || '0'
    # pp "Checking i=#{i}, va=#{va}, vb=#{vb}, res=#{res}, rem=#{rem}"
    
    if va == '0'
      if vb == '0'
        # pp "Set res 1"
        res.prepend(rem)
        rem = '0'
      else # vb == '1'
        if rem == '0'
          # pp "Set res 2"
          res.prepend('1')
        else # rem == '1'
          # pp "Set res 3"
          res.prepend('0')
          rem = '1'
        end
      end
    else # va == '1'
      if vb == '0'
        if rem == '0'
          # pp "Set res 4"
          res.prepend('1')
        else # rem == '1'
          # pp "Set res 5"
          res.prepend('0')
          rem = '1'
        end
      else # vb == '1'
        if rem == '0'
          # pp "Set res 6"
          res.prepend('0')
          rem = '1'
        else # rem == '1'
          # pp "Set res 7"
          res.prepend('1')
          rem = '1'
        end
      end
    end
    
    # pp "Checked i=#{i}, va=#{va}, vb=#{vb}, res=#{res}, rem=#{rem}"
    puts
  end
  
  res = res[1..-1] if res[0] == '0'
  res
end

## improvement: count '1's in va, vb and rem
```

### Use built-in binary to integer conversion

The problem statement doesn't prohibit us to use built-in binary to integer conversion, so just use that


Complexity: `O(max(M,N))`

```
Runtime: 52 ms, faster than 86.21% of Ruby online submissions for Add Binary.
Memory Usage: 210 MB, less than 81.38% of Ruby online submissions for Add Binary.
```

```ruby
def add_binary(a, b)
  va = a.to_i(2)
  vb = b.to_i(2)
  (va + vb).to_s(2)
end
```

## 43. Multiply Strings

https://leetcode.com/problems/multiply-strings/

### Simulation

Just simulation the multiplication process that we learned from primary school.

Complexity: `O(NxM)`

```
Runtime: 208 ms, faster than 14.16% of Ruby online submissions for Multiply Strings.
Memory Usage: 210.4 MB, less than 27.43% of Ruby online submissions for Multiply Strings.
```

```ruby
# @param {String} num1
# @param {String} num2
# @return {String}
def multiply(num1, num2)
  n1 = num1.length
  n2 = num2.length
  res = 0
  
  for i in (-1).downto(-n2)
    rem = 0
    temp_res = ''
    for j in (-1).downto(i+1)
      temp_res.prepend('0')
    end
    for j in (-1).downto(-n1)
      x = num2[i].to_i * num1[j].to_i + rem
      rem = x / 10
      temp_res.prepend((x % 10).to_s)
    end
    
    temp_res.prepend(rem.to_s) if rem > 0
    
    # add temp_res to res
    res += temp_res.to_i(10)
  end
  
  res.to_s
end
```

## 76. Minimum Window Substring

https://leetcode.com/problems/minimum-window-substring/

Use two pointers / sliding window to progressively check substring.

Complexity: `O(NxM)`

```
Runtime: 764 ms, faster than 7.32% of Ruby online submissions for Minimum Window Substring.
Memory Usage: 212.3 MB, less than 39.02% of Ruby online submissions for Minimum Window Substring.
```

```ruby
# @param {String} s
# @param {String} t
# @return {String}
def min_window(s, t)
  @s = s
  @n = s.length
  @t = t
  @count_t_h = count_t
  # pp "t_count=#{@t_count}"
  @h = {}
  
  min_result = 999_999
  result = ''
  
  left = right = 0
  for right in 0..(@n-1)
    add_to_hash(@s[right])
    break if valid_h
  end
  
  # pp "left=#{left}, right=#{right}"
  if valid_h
    min_result = right - left + 1
    result = @s[left..right]
  end
  
  while left < @n && right < @n
    # increase left to next char in t
    remove_from_hash(@s[left])
    left += 1
    while left < @n && !@t.include?(@s[left])
      left += 1
    end
    break if left >= @n
    
    # pp "left is #{left}, @h is #{@h}"
    
    # check current right is still valid
    if valid_h
      # pp "1 Found new left=#{left}, right=#{right}"
      substring_size = right - left + 1
      if substring_size < min_result
        min_result = substring_size
        result = @s[left..right]
      end
      next
    end
    
    # increase right until have a valid substring (include all chars in t)
    right += 1
    while !valid_h && right < @n
      add_to_hash(@s[right])
      # pp "right is #{right}, @h is #{@h}"
      
      if valid_h
        # pp "2 Found new left=#{left}, right=#{right}"
        substring_size = right - left + 1
        if substring_size < min_result
          min_result = substring_size
          result = @s[left..right]
        end
      end
      
      right += 1
    end
    right -= 1
  end
  
  pp '-'*10
  result
end

def add_to_hash(c)
  return unless @t.include? c
  # pp "Adding to hash: #{c}"
  @h[c] = 0 unless @h[c]
  @h[c] += 1
end

def remove_from_hash(c)
  return unless @h[c]
  @h[c] -= 1
  @h.delete(c) if @h[c] == 0
end

def count_t
  h = Hash.new(0)
  for i in 0..(@t.length-1)
    h[@t[i]] += 1
  end
  # pp "count_t h: #{h}"
  h
end

def valid_h
  @count_t_h.each do |k, v|
    return false unless @h[k]
    return false if @h[k] < v
  end
  true
end
```
