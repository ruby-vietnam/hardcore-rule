# Problem 1: [Keyboard Row](https://leetcode.com/problems/keyboard-row/description/)

Submit đầu tiên dùng map, sau tham khảo từ a **linxGnu** dùng array cho nhanh :omg:

```go
var m = []string{
	"qwertyuiopQWERTYUIOP",
	"asdfghjklASDFGHJKL",
	"zxcvbnmZXCVBNM",
}

var n = make([]byte, 200)

func findWords(words []string) (result []string) {
    for k, v := range m {
		for _, vv := range v {
			n[vv] = byte(k)
		}
	}
	
	for _, x := range words {
		if IsValid(x) {
			result = append(result, x)
		}
	}
    
    return
}

func IsValid(s string) bool {
	strLen := len(s)
	if strLen == 0 {
		return true
	}
	
	idx := n[s[0]]
	for i := 1; i < strLen; i++ {
		if n[s[i]] != idx {
			return false
		}
	}
	return true
}
```
