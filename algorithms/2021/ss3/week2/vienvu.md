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
