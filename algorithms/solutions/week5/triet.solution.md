## Problem 1:
```
func getRow(rowIndex int) []int {
   k := rowIndex + 1
	resp := make([]int, k)
	if k == 1 {
		resp[0] = 1
		return resp
	}
	if k == 2 {
		resp[0] = 1
		resp[1] = 1
		return resp
	}

	// init for k > 2, start from row 2
	resp[0] = 1
	resp[1] = 1

	index := 2
	for i := index; i < k; i++ {
		first := 1
		second := resp[1]
		for j := 1; j < i+1; j++ {
			t := resp[j]
			resp[j] = first + second
			first = t
			if j+1 < i {
				second = resp[j+1]
			} else {
				second = 0
			}
		}
		resp[i] = 1
	}

	return resp

}
```

## Problem 2:
```
func checkValidString(s string) bool {
    if s == ""{
        return true
    }

    return check(s, 0)
}

func check(s string, count int) bool {
    if count < 0 {
		return false
	}
	if s == "" || len(s) == 0 {
		return count == 0
	}

	c := s[0]
	switch c {
	case '(':
		return check(s[1:], count+1)
	case ')':
		return check(s[1:], count-1)
	case '*':
		if check("("+s[1:], count) {
			return true
		}
		if check(")"+s[1:], count) {
			return true
		}
		if check(s[1:], count) {
			return true
		}
	}

	return count == 0 && len(s) == 0
}
```
