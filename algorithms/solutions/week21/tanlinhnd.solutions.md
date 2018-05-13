# Problem 1: [Valid Anagram](https://leetcode.com/problems/valid-anagram/description/)

## Solution 1:
```go
func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }
    
    m1, m2 := make(map[byte]int), make(map[byte]int)
    for i := 0; i < len(s); i++ {
        m1[s[i]]++
        m2[t[i]]++
    }
    
    for k, _ := range m1 {
        if m1[k] != m2[k] {
            return false
        }
    }
    return true
}
```

## Solution 2:
```go
func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }
    record := make([]int, 26)
    count := len(s)

    for _, v := range s {
        record[v-'a']++
    }
    for _, v := range t {

        if record[v-'a'] >= 1 {
            count--
        }
        record[v-'a']--
    }

    return count == 0
}
```
