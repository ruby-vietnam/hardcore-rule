package main

import "fmt"

func countAndSay(n int) string {
	if n == 1 {
		return "1"
	}

	s := countAndSay(n - 1)
	result := ""
	count := 0

	for i := 0; i < len(s); i++ {
		count++
		if i == len(s)-1 || s[i] != s[i+1] {
			result += fmt.Sprintf("%d", count)
			result += fmt.Sprintf("%d", s[i]-'0')
			count = 0
		}
	}

	return result
}

func main() {
	fmt.Println(string(countAndSay(4)))
}
