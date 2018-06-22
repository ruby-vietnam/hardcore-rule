Problem 1:

https://leetcode.com/problems/subdomain-visit-count/description/

```go
func subdomainVisits(cpdomains []string) (result []string) {
    mapResult := make(map[string]int)
    for _, cpdomain := range cpdomains {
        a := strings.Split(cpdomain, " ")
        count, _ := strconv.Atoi(a[0])
        parts := strings.Split(a[1], ".")
        var s string
        for index:=len(parts)-1; index>=0; index-- {
            if s == "" {
                s = parts[index]
            } else {
                s = parts[index] + "." + s
            }
            v, _ := mapResult[s]
            mapResult[s] = v + count
        }
    }
    
    for domain, count := range mapResult {
        result = append(result, fmt.Sprintf("%d %s", count, domain))
    }
    return
}
```
