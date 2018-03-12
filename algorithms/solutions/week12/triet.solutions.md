## Problem 2
```go
func findPoisonedDuration(timeSeries []int, duration int) int {
    if len(timeSeries) == 0 {
        return 0
    }
    
    poisonedTime := 0
    lastAttackTime := -1
    for _, attackTime := range timeSeries {
        if lastAttackTime == -1 {
            lastAttackTime = attackTime
            continue
        }
        if attackTime - lastAttackTime >= duration {
            poisonedTime += duration
        } else if attackTime - lastAttackTime < duration {
            poisonedTime += attackTime - lastAttackTime 
        }
        lastAttackTime = attackTime
    }
    
    poisonedTime += duration
    return poisonedTime
}
```
