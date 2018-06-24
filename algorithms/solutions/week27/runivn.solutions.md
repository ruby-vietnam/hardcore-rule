## Problem 1

https://leetcode.com/problems/subdomain-visit-count/description/


```go

func subdomainVisits(cpdomains []string) []string {

	m := make(map[string]int)
	for _, v := range cpdomains {
		spl := strings.Split(v, " ") // get 1st
		count, _ := strconv.Atoi(spl[0])

		splDot := strings.Split(spl[1], ".")

		var temp string
		for i := len(splDot) - 1; i >= 0; i-- {
			if temp != "" {
				temp = splDot[i] + "." + temp
			} else {
				temp = splDot[i]
			}

			if value, ok := m[temp]; ok {
				m[temp] = value + count
			} else {
				m[temp] = count
			}
		}
	}

	var result []string
	for k, v := range m {
		result = append(result, strconv.Itoa(v)+" "+k)
	}

	return result
}
```
