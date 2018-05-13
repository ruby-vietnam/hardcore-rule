*Problem1: https://leetcode.com/problems/valid-anagram/description/*

```go
func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }
    
    counter := make([]int, 26)
    
    for i, _ := range s {
        counter[s[i] - 'a']++
        counter[t[i] - 'a']--
    }
    
    for i, _ := range counter {
        if counter[i] != 0 {
            return false
        }
    }
    
    return true
}
```
