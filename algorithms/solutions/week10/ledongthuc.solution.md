Problem 1: https://leetcode.com/problems/valid-palindrome-ii/

Time: 32ms
Complexity: O(n)

Solution is the same with Palindrome checking with some change.
When you got a invalid pair character, we have 2 cases, 
  1. the left one is removable character
  2. the right one is removable character

=> just loop over the string 2 twice and skip left/right removable character and make sure the string are a palindrome.
  
  
```go
func validPalindrome(s string) bool {
    if len(s) == 0 {
        return true
    }

    left, right, count := 0, len(s) - 1, 0
    for left < right && count <= 1 {
        if s[left] != s[right] {
            count++
            left++
        } else {
            left++
            right--
        }
    }

    if count < 2 {
        return true
    }

    left, right, count = 0, len(s) - 1, 0
    for left < right  && count <= 2 {
        if s[left] != s[right] {
            count++
            right--
        } else {
            left++
            right--
        }
    }

    return count < 2
}
```
