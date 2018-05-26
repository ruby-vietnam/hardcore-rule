## Problem 2
https://leetcode.com/problems/simplify-path

```go

func simplifyPath(path string) string {

	s := strings.Split(path, "/")

	var arr []string
	for i := range s {
		if s[i] == ".." {
			if len(arr) > 0 {
				arr = arr[:len(arr)-1]
			}
		} else if s[i] == "." {
			continue
		} else if s[i] != "" {
			arr = append(arr, s[i])
		}
	}
	if len(arr) == 0 {
		return "/"
	}

	return "/" + strings.Join(arr, "/")
}

```
