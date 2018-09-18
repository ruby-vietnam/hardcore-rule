Problem 1:

https://leetcode.com/problems/reverse-integer/description

```go
func reverse(x int) (result int) {
    negative := false
    if x < 0 {
        negative = true
        x = -x
    }
    
    for x > 0{
        result *= 10
        result += x % 10
        x /=10
    }
    
    if result > math.MaxInt32 {
        return 0
    }
    
    if negative {
        return -result
    }
    
    return result
}
```

Problem 3:

https://leetcode.com/submissions/detail/176396917/

```go
func checkSubarraySum(nums []int, k int) bool {
	if len(nums) == 0 {
		return false
	}
	checkingMap := make(map[int]int)
	checkingMap[0] = -1
	sum := 0
	for _, item := range nums {
		sum += item
		rem := sum
		if k != 0 {
			rem = sum % k
		}

		if index, ok := checkingMap[rem]; !ok {
			checkingMap[rem] = i
		} else {
			if i-index >= 2 {
				return true
			}
		}
	}
	return false
}

```
