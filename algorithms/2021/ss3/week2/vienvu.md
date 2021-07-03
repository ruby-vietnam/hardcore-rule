#Easy:happy-number
https://leetcode.com/problems/happy-number/

Submission Details:
```
402 / 402 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.5 MB
```
```Go

func contains(n []int, number int) bool {
	for _, v := range n {
		if v == number {
			return true
		}
	}

	return false
}

func isHappy(n int) bool {
	var arraySave []int
	arraySave = append(arraySave, n)
	for true {
		var arrayDigits []int
		numberLetter := strconv.Itoa(n)
		digits := strings.Split(numberLetter, "")

		for _,i := range digits {
			j, err := strconv.Atoi(i)
			if err == nil {
				arrayDigits = append(arrayDigits, j)
			}
		}

		n = 0
		for _, k := range arrayDigits {
			n += k * k
		}
		if n == 1 { break }

		if contains(arraySave, n) { break }
		arraySave = append(arraySave, n)
	}
	if n == 1 { return  true }

	return false
}
```
#Medium: the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

Submission Details:
```
345 / 345 test cases passed.
Status: Accepted
Runtime: 32 ms
Memory Usage: 6.8 MB
```

```Go
var characterSet = []string{"a", "b", "c"}
var allStrings []string
func getHappyString(n int, k int) string {
    allStrings = []string{}
	generateAllStringRec("", len(characterSet), n)
	sort.Strings(allStrings)
	if k > len(allStrings) {
		return ""
	}
	return allStrings[k - 1]
}

func generateAllStringRec(prefix string, n int, k int)  {
	if k == 0 {
		allStrings = append(allStrings, prefix)
		return
	}

	for i := 0; i < n; i++ {
		newPrefix := ""

		if len(prefix) == 0 {
			newPrefix = prefix + characterSet[i]
			generateAllStringRec(newPrefix, n, k - 1)
		} else  {
			if prefix[len(prefix) - 1:] != characterSet[i] {
				newPrefix = prefix + characterSet[i]
				generateAllStringRec(newPrefix, n, k - 1)
			}
		}
	}
}
```