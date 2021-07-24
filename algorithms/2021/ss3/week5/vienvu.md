#

## Easy: excel-sheet-column-title

<https://leetcode.com/problems/excel-sheet-column-title/>

### Submission details

```
18 / 18 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2 MB
```

### implement

```Go
func convertToTitle(columnNumber int) string {
	dict := map[int]string{1:"A", 2:"B", 3:"C", 4:"D", 5:"E", 6:"F", 7:"G", 8:"H", 9:"I",
		10:"J", 11:"K", 12:"L", 13:"M", 14:"N", 15:"O", 16:"P", 17:"Q",
		18:"R", 19:"S", 20:"T", 21:"U", 22:"V", 23:"W", 24:"X", 25:"Y", 26:"Z"}

	result := ""
	for columnNumber > 26 {
		res := columnNumber % 26
		if res == 0 {
			result += "Z"
		} else {
			result = dict[int(res)] + result
		}
		

		columnNumber /= 26
		if res == 0 { columnNumber -= 1}
	}
	if columnNumber != 0 {
		result = dict[columnNumber] + result
	}

	return result
}
```

## Easy: climbing-stairs

<https://leetcode.com/problems/climbing-stairs>

### Submission details

```
45 / 45 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 1.9 MB
```

### Implement

```Go
func climbStairs(n int) int {
	pre := 1
	curr := 1
	temp := 0
	for i := 1; i < n; i++ {
		temp = curr
		curr = pre + curr
		pre = temp
	}

	return curr
}
```

