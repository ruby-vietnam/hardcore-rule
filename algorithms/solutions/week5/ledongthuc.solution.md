## Problem 1

https://play.golang.org/p/boUxINUIn9Y

```golang
func getRow(rowIndex int) []int {
	result := make([]int, rowIndex+1, rowIndex+1)
	result[0] = 1
	for row := 0; row < rowIndex; row++ {
		for columnIndex := row+1; columnIndex >= 1; columnIndex-- {
			result[columnIndex] += result[columnIndex-1]
		}
	}
	return result
}
```
## Problem 2

https://play.golang.org/p/_gwhk60eqOu

```golang
func checkValidString(s string) bool {
	if len(s) == 0 {
		return true
	}

	leftParenthesis := rune('(')
	rightParenthesis := rune(')')
	any := rune('*')

	var leftChecker, rightChecker int
	for _, c := range s {
		if c != leftParenthesis && c != rightParenthesis && c != any {
			return false
		}
		switch c {
		case leftParenthesis:
			leftChecker++
			rightChecker++
		case rightParenthesis:
			leftChecker--
			rightChecker--
		case any:
			leftChecker-- 
			rightChecker++ 
		default:
			return false
		}

		if rightChecker < 0 { 
			return false
		} else if leftChecker < 0 { 
			leftChecker = 0
		}
	}
	return leftChecker == 0
}
```
