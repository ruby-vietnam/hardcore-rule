# Problem 1

```go
func countAndSay(n int) string {
    result := "1"
	str := ""
	count := 1
	for i := 1; i < n; i++ {
		for j := 0; j < len(result); j++ {
			if j+1 != len(result) && result[j+1] == result[j] {
				count++
			} else {
				str += strconv.Itoa(count) + string(result[j])
				count = 1
			}
		}
		result = str
		str = ""
	}
	return result
}
```