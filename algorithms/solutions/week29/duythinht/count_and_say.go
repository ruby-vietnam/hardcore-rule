package duythinht

func countAndSay(n int) string {
	if n == 1 {
		return "1"
	}
	prev := countAndSay(n - 1)

	result := ""
	c := prev[0]
	count := 0

	for i := 0; i < len(prev); i++ {
		if prev[i] != c {
			result += fmt.Sprintf("%d%c", count, c)
			c = prev[i]
			count = 0
		}
		count++
	}
	result += fmt.Sprintf("%d%c", count, c)
	return result
}
