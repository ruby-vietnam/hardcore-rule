# Problem 1: [Subdomain Visit Count](https://leetcode.com/problems/subdomain-visit-count/description/)

```go
import "strings"
import "strconv"
import "fmt"

func subdomainVisits(cpdomains []string) []string {
    visit := make(map[string]int, len(cpdomains))
    for _, v := range cpdomains {
        cp := strings.Split(v, " ")
        t := cp[1]
        
        for {
            m, _ := strconv.ParseInt(cp[0], 10, 32)
            if _, ok := visit[t]; ok {
                visit[t] = visit[t] + int(m)
            } else {
                visit[t] = int(m)
            }
            if d := strings.Index(t, "."); d == -1 {
                break
            } else {
                tmp := []rune(t)
                t = string(tmp[d+1:])
            }
        }
    }
    res := make([]string, len(visit))
    n := 0
    for k, v := range visit {
        res[n] = fmt.Sprintf("%d %s", v, k)
        n++
    }
    return res
    
}
```
