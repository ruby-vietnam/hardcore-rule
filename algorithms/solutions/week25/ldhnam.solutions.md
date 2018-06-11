# Problem 1

```go
var (
	top = "qwertyuiop"
	mid = "asdfghjkl"
	bot = "zxcvbnm"
)

func getCount(word string, ch byte, count int) int {
	for i := 0; i < len(word); i++ {
		if ch == word[i] {
			count++
		}
	}

	return count
}

func findWords(words []string) []string {
	var res []string
	for i := 0; i < len(words); i++ {
		countTop := 0
		countMid := 0
		countBot := 0
		s := strings.ToLower(words[i])
		for j := 0; j < len(s); j++ {
			countTop = getCount(top, s[j], countTop)
			countMid = getCount(mid, s[j], countMid)
			countBot = getCount(bot, s[j], countBot)
		}

		if (countTop != 0 && countMid == 0 && countBot == 0) ||
					(countTop == 0 && countMid != 0 && countBot == 0) ||
					(countTop == 0 && countMid == 0 && countBot != 0) {
				res = append(res, words[i])
		}
	}

	return res
}
```