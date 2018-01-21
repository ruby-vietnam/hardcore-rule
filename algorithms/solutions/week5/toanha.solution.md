## Problem 1

```golang
func getRow(rowIndex int) []int {
	if rowIndex == 0 {
		return []int{1}
	}

	if rowIndex == 1 {
		return []int{1, 1}
	}

	previousRow := getRow(rowIndex - 1)
	row := []int{}
	for i := 0; i < rowIndex; i++ {
		if i-1 >= 0 {
			row = append(row, previousRow[i]+previousRow[i-1])
		} else {
			row = append(row, previousRow[i])
		}
	}

	return append(row, 1)
}
```

## Problem 2
```golang

func checkValidString(s string) bool {
	var countOpen int
	var countClose int

	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			// Increase left parenthesisn
			// Increase right parenthesisn because we need a right parenthesis for the left one
			countOpen++
			countClose++
		} else {
			if s[i] == ')' {
				// Decrease left parenthesisn (if there is any left parenthesis before)
				// Decrease right parenthesisn
				if countOpen > 0 {
					countOpen--
				}
				countClose--
			} else {
				if countOpen > 0 {
					// Decrease left parenthesisn (if there is any left parenthesis before)
					countOpen--
				}
				// We can use * as ( so increase right parenthesis need
				countClose++
			}
		}

		// Check if there is any right parenthesis
		if countClose < 0 {
			return false
		}
	}
	return countOpen == 0
}
```
