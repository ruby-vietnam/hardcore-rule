# Problem 1: [Plus One](https://leetcode.com/problems/plus-one/description/)

```go
func plusOne(digits []int) []int {
	digitLen := len(digits)
	if digitLen == 0 {
		return []int{}
	}
	sign := 0
	for i := digitLen - 1; i >= 0; i-- {
		if sign == 1 {
			digits[i]++
			if digits[i] > 9 {
				digits[i] = 0
				sign = 1
			} else {
				sign = 0
				break
			}
		} else {
			if digits[i] == 9 {
				digits[i] = 0
				sign = 1
			} else {
				digits[i] = digits[i] + 1
				break
			}
		}
	}
	if sign == 1 {
		digits = append([]int{1}, digits...)
	}
	return digits
}
```
