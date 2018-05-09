## Problem 1

```go
func plusOne(digits []int) []int {
    m := 0
    digits[len(digits) -1] +=1
    for i := len(digits)-1; i >= 0; i-- {
        if m != 0 {
            digits[i] += m
        }
        if digits[i] > 9 {
            digits[i] = 10 - digits[i]
            m = 1
        } else {
            m = 0
        }
    }
    
    if m != 0 {
        digits = append([]int{1}, digits...)
    }
    return digits
}
```
