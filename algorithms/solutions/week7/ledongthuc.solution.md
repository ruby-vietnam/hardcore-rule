Problem 1:

https://play.golang.org/p/VzzBzjOa9RB

```go
func firstUniqChar(s string) int {
	var charCounting [256]int
	for _, rune := range s {
		charCounting[int(rune)] += 1
	}
	for index, rune := range s {
		if charCounting[int(rune)] == 1 {
			return index
		}
	}
	return -1
}
```
