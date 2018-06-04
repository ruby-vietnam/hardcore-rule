# Problem 1

https://leetcode.com/problems/sum-of-square-numbers/description/

```go
func judgeSquareSum(c int) bool {
    low, high := 0, int(math.Sqrt(float64(c)))
    
    for low <= high {
        if low * low + high * high < c {
            low += 1
        } else if low * low + high * high > c {
            high -= 1
        } else {
            return true
        }
    }
    
    return false
}
```

# Problem 2

https://leetcode.com/problems/largest-number/description/

```go
func largestNumber(nums []int) string {
	length := len(nums)
	if length == 0 {
		return ""
	}
	numberStrs := make([]string, 0, length)
	isZero := true
	for i := 0; i < length; i++ {
		if nums[i] != 0 {
			isZero = false
		}
		numberStrs = append(numberStrs, strconv.Itoa(nums[i]))
	}
	if isZero {
		return "0"
	}
	sort.Slice(numberStrs, func(i, j int) bool {
		tmpS1 := numberStrs[i] + numberStrs[j]
		tmpS2 := numberStrs[j] + numberStrs[i]
		if tmpS1 < tmpS2 {
			return false
		}
		return true
	})
	return strings.Join(numberStrs, "")
}
```

# Problem 3

https://leetcode.com/problems/coin-change/description/

```go
func coinChange(coins []int, amount int) int {
    if amount == 0 {
        return 0
    }
    if len(coins) == 0 {
        return -1
    }
    
    checking := make([]int, amount+1)
    for i:= 1; i<=amount; i++ {
        checking[i] = amount+1
    }
    for checkingIndex, _ := range checking {
        for _, coinValue := range coins {
            if previous:=checkingIndex-coinValue; previous >= 0 && checking[previous] >= 0 {
                if checking[previous]+1 < checking[checkingIndex] {
                    checking[checkingIndex] = checking[previous]+1
                }
            }
        }
    }
    if checking[amount] > amount {
        return -1
    }
    return checking[amount]
}
```
