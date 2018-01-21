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

Problem 3:

https://play.golang.org/p/M6Tp4Rg2-kL

```golang

func maxEnvelopes(envelopes [][]int) int {
	if len(envelopes) == 0 {
		return 0
	}
	if len(envelopes) == 1 {
		return 1
	}
	envelopes = MergeSort(envelopes) // sort by width

	max := 1
	maxOfCases := make([]int, len(envelopes), len(envelopes))
	for index, _ := range envelopes {
		maxOfCases[index] = 1
		for indexOfPossibleCase := 0; indexOfPossibleCase < index; indexOfPossibleCase++ {
			if IsFitToLink(envelopes[indexOfPossibleCase], envelopes[index]) {
				countOfCase := maxOfCases[indexOfPossibleCase] + 1
				if countOfCase > maxOfCases[index] {
					maxOfCases[index] = countOfCase
				}
			}
		}
		if maxOfCases[index] > max {
			max = maxOfCases[index]
		}
	}

	return max

}

func IsFitToLink(a, b []int) bool {
	return a[0] < b[0] && a[1] < b[1]
}

func Merge(l, r [][]int) [][]int {
	ret := make([][]int, 0, len(l)+len(r))
	for len(l) > 0 || len(r) > 0 {
		if len(l) == 0 {
			return append(ret, r...)
		}
		if len(r) == 0 {
			return append(ret, l...)
		}
		if l[0][0] <= r[0][0] {
			ret = append(ret, l[0])
			l = l[1:]
		} else {
			ret = append(ret, r[0])
			r = r[1:]
		}
	}
	return ret
}

func MergeSort(s [][]int) [][]int {
	if len(s) <= 1 {
		return s
	}
	n := len(s) / 2
	l := MergeSort(s[:n])
	r := MergeSort(s[n:])
	return Merge(l, r)
}
```
