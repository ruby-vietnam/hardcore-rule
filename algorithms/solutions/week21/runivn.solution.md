## Problem 1

Problem met once before so I derived a new solution. A bit tricky but still not been proved as wrong
```go
func isAnagram(s string, t string) bool {
    if len(s) != len(t){
        return false
    }
    var num byte
    var sum byte
    for i := range s {
        num = num ^ s[i] ^ t[i]
        sum += s[i]*s[i] - t[i]*t[i]
    }

    return num == 0 && sum == 0
}

```
