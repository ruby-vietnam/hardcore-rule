## Problem 1

```go
func charDict(s string) map[rune]int {
	result := map[rune]int{}
	for _, b := range s {
		_, ok := result[b]
		if ok {
			result[b]++
		} else {
			result[b] = 1
		}
	}
	return result
}

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	ds := charDict(s)
	dt := charDict(t)
	for k, vs := range ds {
		vt, _ := dt[k]
		if vt != vs {
			return false
		}
	}
	return true
}
```
