## Problem 1

https://leetcode.com/problems/power-of-four/

We check if number bit 1 of num is equal to 1, and number bit 1 of (num-1) also equal to 1

```go
func isPowerOfFour(num int) bool {
	return num == 1 || (bitcount(num) == 1 && (bitcount(num-1)%2 == 0))
}


func bitcount(num int) int {
	var count int
	for num > 0 {
		num = num & (num - 1)
		count++
	}

	return count
}
```
