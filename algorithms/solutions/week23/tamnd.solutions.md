### Problem 1

```go
import "strings"

func simplifyPath(path string) string {
	parts := strings.Split(path, "/")
	ret := make([]string, len(parts))
	index := 0
	for _, part := range parts {
		switch part {
		case ".":
			continue
		case "":
			continue
		case "..":
			if index > 0 {
				index--
			}
		default:
			{
				ret[index] = part
				index++
			}
		}
	}
	ret = ret[0:index]
	return "/" + strings.Join(ret, "/")
}
```
