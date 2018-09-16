# Problem 1

```go
func reverse(x int) int {
  sign := 1
  digit := 0
  reversed := 0
  
  maxInt := 2147483647

  if x < 0 {
    sign = -1
    x = x * (-1)
  }

  for x != 0 {
    digit = x % 10
    reversed = reversed * 10 + digit
    x = x / 10    
  }
    
  if reversed > maxInt {
    return 0
  }

  return reversed * sign  
}
```
