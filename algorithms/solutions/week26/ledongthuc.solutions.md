Problem 1:

https://leetcode.com/problems/find-the-difference/description/

```go
func findTheDifference(s string, t string) byte {
    var differentByte byte
    if len(s) == len(t) {
        return differentByte
    }
    
    m := make([]int, 10000)
    for index, _ := range t {
        m[t[index]]++
        if index <= len(s) -1 {
            m[s[index]]++
        }
    }
    
    for index, v := range m {
        if v % 2 != 0 {
            return byte(index)
        }
    }
    return differentByte
}
```
