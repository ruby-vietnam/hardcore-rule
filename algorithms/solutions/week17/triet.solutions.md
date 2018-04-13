## Problem 1

```go
func isIsomorphic(s string, t string) bool {
    runes := []rune(s)
    runet := []rune(t)

    ms := map[rune]rune{}
    mt := map[rune]rune{}
    for i := 0; i < len(runes); i++ {
        if value, exists := mt[runet[i]]; exists {
            runet[i] = value
            continue
        }
        
        if _, exists := ms[runes[i]]; exists {
                return false
            
        }
        ms[runes[i]] = runet[i]
        mt[runet[i]] = runes[i]
        runet[i] = runes[i]
    }

    return string(runes) == string(runet)
}
```
