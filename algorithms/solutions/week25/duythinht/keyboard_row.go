package duythinht

var (
	top    = "qwertyuiop"
	mid    = "asdfghjkl"
	bottom = "zxcvbnm"

	charsRow = make(map[byte]int)
)

func init() {
	for _, c := range top {
		charsRow[byte(c)] = 1
		charsRow[byte(c-32)] = 1
	}
	for _, c := range mid {
		charsRow[byte(c)] = 2
		charsRow[byte(c-32)] = 2
	}
	for _, c := range bottom {
		charsRow[byte(c)] = 3
		charsRow[byte(c-32)] = 3
	}
}

func isOneRow(word string) bool {
	for i := 0; i < len(word)-1; i++ {
		if charsRow[word[i]] != charsRow[word[i+1]] {
			return false
		}
	}
	return true
}

func findWords(words []string) []string {
	result := make([]string, 0)
	for _, word := range words {
		if isOneRow(word) {
			result = append(result, word)
		}
	}
	return result
}
