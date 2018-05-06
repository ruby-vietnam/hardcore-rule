### Prolem 1 - [Plus One](https://leetcode.com/problems/plus-one/description/)

Status:
```
  ✔ Accepted
  ✔ 109/109 cases passed (0 ms)
```

```go
func plusOne(digits []int) []int {
  n := len(digits)
  i := n - 1
  for i >= 0 {
    if digits[i] == 9 {
      digits[i] = 0
      i--
    } else {
      digits[i]++
      return digits
    }
  }
  // digits = [9, 9, 9, ..., 9]
  ret := make([]int, n+1)
  ret[0] = 1
  return ret
}
```

### Problem 2 - [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/description/)

Status:
```
  ✔ Accepted
  ✔ 1079/1079 cases passed (0 ms)
```

Code:

```go
func myAtoi(str string) int {
    n := len(str)
    if n == 0 {
        return 0
    }
    
    i := 0
    
    // Skip white spaces
    for i < n && str[i] == ' ' {
        i++
    }
    
    // Read sign
    sign := 1
    if i < n {    
        if str[i] == '-' {
            sign = -1
            i++
        } else if str[i] == '+' {
            sign = 1
            i++
        }
    }
    
    ret := 0
    for i < n && str[i] >= '0' && str[i] <= '9' {
        ret = ret * 10 + int(str[i] - '0')
        if ret > math.MaxInt32 {
            break
        } else {
            i++
        }
    }
    ret = ret * sign
    
    // Check overflow
    if ret < math.MinInt32 {
        return math.MinInt32
    }
    if ret > math.MaxInt32 {
        return math.MaxInt32
    }
    return ret
    
}
```
