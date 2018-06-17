## Problem 1
https://leetcode.com/problems/find-the-difference/description/

```go
func findTheDifference(s string, t string) byte {
	var u byte
	for _, v := range s {
		u = u ^ byte(v)
	}

	for _, v := range t {
		u = u ^ byte(v)
	}

	return u
}
```
