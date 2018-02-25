## Problem 1

https://leetcode.com/problems/valid-palindrome-ii

```golang
func isValidPalindrome(s string, i, j int) bool {
	for k := i; k <= i+(j-i)/2; k++ {
		if s[k] != s[j-k+i] {
			return false
		}
	}

	return true
}

func validPalindrome(s string) bool {
	l := len(s)

	for i := 0; i < l/2; i++ {
		j := l - 1 - i
		if s[i] != s[j] {
			return isValidPalindrome(s, i, j-1) || isValidPalindrome(s, i+1, j)
		}
	}

	return true
}
```

## Problem 3

https://leetcode.com/problems/is-subsequence

```golang
func isSubsequence(s string, t string) bool {
	var i, j int
	for i < len(s) && j < len(t) {
		if s[i] == t[j] {
			i++
		}
		j++
	}
	return i == len(s)
}
```
