## Problem 1
https://leetcode.com/problems/count-and-say/description/

```go

func countAndSay(n int) string {
	var result = "1"
	var temp strings.Builder

	for i := 1; i <= n-1; i++ {
		count := 1
		for j := 0; j <= len(result)-1; j++ {
			if j < len(result)-1 && result[j] == result[j+1] {
				count++
			} else {
				temp.WriteString(strconv.Itoa(count))
				temp.Write([]byte{result[j]})
				count = 1
			}
		}

		if result == "1" {
			result = "11"
		} else {
			result = temp.String()
		}

		temp.Reset()
	}

	return result
}

```
