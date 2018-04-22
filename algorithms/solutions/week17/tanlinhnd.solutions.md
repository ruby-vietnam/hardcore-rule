# Problem 1: [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/description/)

```go
func isIsomorphic(s string, t string) bool {
	if len(s) <= 1 {
		return true
	}

	t1, t2 := make(map[byte]byte), make(map[byte]byte)
	for i := range s {
		if t1[s[i]] == 0 && t2[t[i]] == 0 {
			t1[s[i]] = t[i]
			t2[t[i]] = s[i]
		} else {
			if t1[s[i]] != t[i] || t2[t[i]] != s[i] {
				return false
			}
		}
	}
	return true
}
```
