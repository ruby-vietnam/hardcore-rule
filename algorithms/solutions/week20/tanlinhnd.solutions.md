# Problem 1: [Plus One](https://leetcode.com/problems/plus-one/description/)

```go
func plusOne(digits []int) []int {
	digitLen := len(digits)
	if digitLen == 0 {
		return []int{}
	}
	tmp, sign := digits[:], 0
	for i := digitLen - 1; i >= 0; i-- {
		if sign == 1 {
			tmp[i]++
			if tmp[i] > 9 {
				tmp[i] = 0
				sign = 1
			} else {
				sign = 0
				break
			}
		} else {
			if tmp[i] == 9 {
				tmp[i] = 0
				sign = 1
			} else {
				tmp[i] = tmp[i] + 1
				break
			}
		}
	}
	if sign == 1 {
		tmp = append([]int{1}, tmp...)
	}
	return tmp
}
```
