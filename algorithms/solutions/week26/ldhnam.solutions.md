# Problem 1

```go
func findTheDifference(s string, t string) byte {
	m := make(map[byte]int)
	for i := 0; i < len(s); i++ {
		m[s[i]-'a']--
		m[t[i]-'a']++
	}
	m[t[len(t)-1]-'a']++
	for k, v := range m {
		if v == 1 {
			return (byte)(k + 'a')
		}
	}

	return '0'
}
```