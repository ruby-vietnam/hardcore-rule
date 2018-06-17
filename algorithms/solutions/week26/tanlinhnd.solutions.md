# Problem 1: [Find the Difference](https://leetcode.com/problems/find-the-difference/description/)

```go
func findTheDifference(s string, t string) byte {
    var res byte
    for i := 0; i < len(s); i++ {
        res ^= s[i] ^ t[i]
    }
    return res ^ t[len(t) - 1]
}
```
