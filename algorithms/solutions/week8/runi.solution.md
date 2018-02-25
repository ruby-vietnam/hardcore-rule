## Problem 1

https://leetcode.com/problems/longest-word-in-dictionary/description/

```go

func longestWord(words []string) string {
	sort.Slice(words, func(i, j int) bool {
		return len(words[i]) > len(words[j])
	})

	var longest2 []string
	var maxLength = 0

	for _, l := range words {
		k := 1
		flag := false
		for k < len(l) && !flag {
			if !containsInArray(words, l[0:k]) {
				flag = true
			}
			k++
		}

		if maxLength < len(l) {
			if !flag {
				longest2 = []string{}
				maxLength = len(l)
				longest2 = append(longest2, l)
			}
		} else if maxLength == len(l) {
			if !flag {
				longest2 = append(longest2, l)
			}
		}
	}

	if len(longest2) > 0 {
		sort.Slice(longest2, func(i, j int) bool {
			for k := 0; k < len(longest2[i]); k++ {
				if longest2[i][k] < longest2[j][k] {
					return true
				} else if longest2[i][k] > longest2[j][k] {
					return false
				}
			}

			return true
		})

		return longest2[0]
	}

	return ""
}

func containsInArray(w []string, c string) bool {
	for _, v := range w {
		if c == v {
			return true
		}
	}

	return false
}
```
