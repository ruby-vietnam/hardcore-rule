package actions

import "strings"

func ptrStr(s string) *string {
	return &s
}

func isAlgorithmPR(body string) bool {
	patterns := []string{"- [ ] Problem", "- [x] Problem"}
	for _, pattern := range patterns {
		if strings.Contains(body, pattern) {
			return true
		}
	}
	return false
}
