## Problem 1 [Sum of Square Numbers](https://leetcode.com/problems/sum-of-square-numbers/description/)

```go
func judgeSquareSum(c int) bool {
    l, r := 0, int(math.Sqrt(float64(c)))
    for l <= r {
        n := l*l + r*r
        if n == c {
            return true
        } else if n > c {
            r--
        } else {
            l++
        }
    }
    return false
}
```

```go
  func judgeSquareSum(c int) bool {
      if c == 0 {
        return true
      }
      for c%2 == 0 {
        c = c/2
      }

      for i := 3; i*i <= c; i = i + 2 {
          count := 0
          if c % i == 0 {
                for c % i == 0 {
                  count++
                  c = c/i
                }
                // Fermat theorem
                if (i%4==3) && (count%2 == 1) {
                  return false
                }
          }    
      }

    return c%4 != 3
  }
```
