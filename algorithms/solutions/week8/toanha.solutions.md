## Problem 1

https://leetcode.com/problems/longest-word-in-dictionary

Brute-force, kiểm tra từng phần tử trong mảng có xuất hiện trong arr ban đầu hay không

Ví dụ:
input ["a", "banana", "app", "appl", "ap", "apply", "apple"]
check phần tử `banana` sẽ check các case `b`, `ba`, `ban`, `bana`, `banan`

```golang
func beginWith(arr []string, str string) bool {
	var b bool
	for i := 1; i < len(str); i++ {
		b = false
		for j := 0; j < len(arr); j++ {
			if arr[j] != str && str[:i] == arr[j] {
				b = true
			}
		}
		if !b {
			return false
		}
	}
	return true
}

func longestWord(words []string) string {
	var word string
	for _, w := range words {
		if len(w) > len(word) ||
			(len(w) == len(word) && w < word) {
			if beginWith(words, w) {
				word = w
			}
		}
	}
	return word
}
```
