## Problem 1

https://leetcode.com/problems/first-unique-character-in-a-string/description/


Use an array with 26 characters to count

```go

func firstUniqChar(s string) int {
	if len(s) == 0 {
		return -1
	}

	a := make([]int, 26)

	for _, v := range s {
		a[int(v)-97]++
	}

	for i, v := range s {
		if a[int(v)-97] == 1 {
			return i
		}
	}

	return -1
}
```
