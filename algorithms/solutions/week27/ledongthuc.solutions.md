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

Problem 2:

```go
func dirReduc(input map[string]string) map[string]string {
	mapping := map[string]string {
		"NORTH": "SOUTH",
		"SOUTH": "NORTH",
		"EAST": "WEST",
		"WEST": "EAST",
	}
	var stack []string
	for _, item := range input {
		if len(stack) > 0 && mapping[item] == stack[len(stack)-1] {
			stack = stack[:len(stack)-1]
		} else {
			stack = append(stack, item)
		}
	}
}
```

Problem 3:

https://leetcode.com/problems/chalkboard-xor-game/solution/

```go
func xorGame(nums []int) bool {
    /*
     * With len of nums's even, Alice will try to pick a item in list and the remaining will be odd XOR of them should be != 0
     * Next turn, Bob will do the same to make sure the even remaining item have XOR !=0
     * Finally, last item, Bod will pick and the remaining = []. XOR will be 0 => Alice win
     */
    length :=len(nums)
    if length % 2 ==0 {
        return true
    }
    
    /*
     * If init list have XOR == 0 => Alice win also
     */ 
    checking := nums[0]
    for index := 1; index < length; index++ {
            checking ^= nums[index];
    }
    if checking == 0 {
        return true
    }
    
    return false
    // Another cases, Alice have able to be fail
}
```
