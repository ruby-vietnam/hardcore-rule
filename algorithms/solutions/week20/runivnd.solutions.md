## Problem 1
https://leetcode.com/problems/plus-one/description/

```go
func plusOne(digits []int) []int {
	var newDigits []int

	for i := len(digits) - 1; i >= 0; i-- {
		if digits[i] == 9 {
			digits[i] = 0
		} else {
			digits[i] = digits[i] + 1
			return digits
		}

		if i == 0 {
			newDigits = append(newDigits, 1)
			newDigits = append(newDigits, digits...)

		}
	}
	return newDigits
}
```
