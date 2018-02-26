## Problem 1

https://leetcode.com/articles/valid-palindrome-ii/


We check if this string is palindrom or 2 sub strings concreated from delete a char are paladrom or not
```go
func validPalindrome(s string) bool {
	for i := 0; i < len(s)/2; i++ {
		if s[i] != s[len(s)-i-1] {
			return isPalindrom(s[:i]+s[i+1:]) || isPalindrom(s[:len(s)-i-1]+s[len(s)-i:])
		}
	}

	return true
}

func isPalindrom(s string) bool {
	for i := 0; i < len(s)/2; i++ {
		if s[i] != s[len(s)-i-1] {
			return false
		}
	}

	return true
}
```
