# Problem 1:

https://leetcode.com/problems/keyboard-row/description/

```go
func findWords(words []string) (result []string) {
    // 20 - 40 - 60
    lines := "qwertyuiopQWERTYUIOPasdfghjklASDFGHJKLzxcvbnmZXCVBNM"
    for _, ws := range words {
        line := 0
        for _, w := range ws {
            index := strings.IndexRune(lines, w)
            if index < 20 && (line == 0 || line == 1) {
                line = 1
                continue
            } else if index >= 20 && index < 38 && (line == 0 || line == 2) {
                line = 2
                continue
            } else if index >= 38 && (line == 0 || line == 3) {
                line = 3
                continue
            } else {
                line = -1
                break
            }
        }
        if line != -1 {
            result = append(result, ws)
        }
    }
    return result
}
```
