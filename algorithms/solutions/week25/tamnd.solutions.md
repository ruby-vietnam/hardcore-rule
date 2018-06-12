## Problem 1

```go
import "regexp"

var re = regexp.MustCompile("^([qwertyuiop]*|[asdfghjkl]*|[zxcvbnm]*)$")
func findWords(words []string) []string {
  ret := make([]string, 0, len(words))
  for _, word := range words {
    if found := re.MatchString(word); found {
      ret = append(ret, words)
    }
  }
  return ret
}
```
