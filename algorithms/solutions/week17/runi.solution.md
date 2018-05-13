## Problem 1

https://leetcode.com/problems/isomorphic-strings/description/

We use 2 maps: 1 for storing character from s[i] -> t[i], another for storing if t[i] has appear before in t

- If s[i] takes the first time appear in s, then t[i] must be the first time either.
- If not, s[i] should always be equal to t[i]
```go
func isIsomorphic(s string, t string) bool {
	c1 := make(map[byte]byte)
	c2 := make(map[byte]bool)

	for i := range s {
		if _, ok := c1[s[i]]; !ok {
			if _, ok = c2[t[i]]; ok {
				return false
			} else {
				c2[t[i]] = true
			}

			c1[s[i]] = t[i]
		}

		if c1[s[i]] != t[i] {
			return false
		}
	}

	return true
}
```
