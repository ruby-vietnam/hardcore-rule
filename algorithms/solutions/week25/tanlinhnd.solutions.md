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

# Problem 2: [Friend Circles](https://leetcode.com/problems/friend-circles/description/)

```go
var visited = make([]int, 100)

func findCircleNum(M [][]int) int {
    ln := len(M)
    if ln == 0 {
        return 0
    }
    
    count := 0
    
    for i := 0; i < ln; i++ {
        if visited[i] == 0 {
            visited[i] = 1
            dfs(M, i)
            count++
        }
    }
    return count
}

func dfs(M [][]int, i int) {
    for j := 0; j < len(M); j++ {
        if M[i][j] == 1 && visited[j] == 0 {
            visited[j] = 1
            dfs(M, j)
        }
    }
}
```
