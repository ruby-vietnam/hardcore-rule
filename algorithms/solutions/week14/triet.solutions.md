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
Use logarit:

```go
func isPowerOfFour(num int) bool {
    if num <= 0 {
        return false
    }
    
    if num == 1 {
        return true
    }
    log := math.Log(float64(num))/math.Log(4)
    return (math.Ceil(log) == log ) && (math.Floor(log) == log)
}
```
