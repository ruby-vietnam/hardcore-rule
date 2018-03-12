## Problem 1

```go
func canWinNim(n int) bool {
    return n % 4 != 0
}
```

## Problem 2

```go
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func findPoisonedDuration(timeSeries []int, duration int) int {
    if len(timeSeries) == 0 {
        return 0
    }

    totalTime := 0
    maxPoisonTime := timeSeries[0]
    for _, time := range timeSeries {
        if time + duration > maxPoisonTime {
            addedTime := time + duration - max(maxPoisonTime, time)
            totalTime = totalTime + addedTime
            maxPoisonTime = time + duration
        }
    }

    return totalTime
}
```
