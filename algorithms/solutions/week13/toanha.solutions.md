# Problem 1: Maximum Product of Three Numbers

URL: https://leetcode.com/problems/maximum-product-of-three-numbers/description/

```golang
func maximumProduct(nums []int) int {
  l := len(nums)
  sort.Ints(nums)
  a := nums[0] * nums[1] * nums[l-1]
  b := nums[l-1] * nums[l-2] * nums[l-3]
  if a >= b {
    return a
  }
  return b
}
```

# Problem 3: Valid Number

URL: https://leetcode.com/problems/valid-number/description/

```golang
func isNumber(s string) bool {
  s = strings.Trim(s, " ")
  var dotFlag, eFlag, eRightFlag, numberFlag bool

  for i := 0; i < len(s); i++ {
    if s[i] >= '0' && s[i] <= '9' {
      numberFlag = true
      eRightFlag = true
    } else if s[i] == '.' {
      if dotFlag || eFlag {
        return false
      }
      dotFlag = true
    } else if s[i] == 'e' {
      if eFlag || !numberFlag {
        return false
      }
      eFlag = true
      eRightFlag = false
    } else if s[i] == '-' || s[i] == '+' {
      if i != 0 && s[i-1] != 'e' {
        return false
      }
    } else {
      return false
    }
  }

  return numberFlag && eRightFlag
}
```
