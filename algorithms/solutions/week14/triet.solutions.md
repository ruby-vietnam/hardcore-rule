## Problem 1

Use for:

```go
func isPowerOfFour(num int) bool {
    if num == 1 {
        return true
    }
    init := 4
    for {
        if init == num {
            return true
        }
        if init > num {
            return false
        }
        init = init*4
    }
}
```
