#

## Easy 1: excel-sheet-column-title

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

## Easy 2: climbing-stairs

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

## Medium 1: house-robber

<https://leetcode.com/problems/house-robber>

### Submission details

```
68 / 68 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2 MB
```

### Implement

```Go
func rob(nums []int) int {
	prevSum := 0
	currSum := 0
	for i := 0; i < len(nums); i++ {
		temp := prevSum
		prevSum = currSum
		currSum = Max(temp + nums[i], prevSum)
	}
	return  currSum
}

func Max(x, y int) int {
	if x < y {
		return y
	}
	return x
}
```

## Medium 2: house-robber-ii

<https://leetcode.com/problems/house-robber-ii/>

### Submission details

```
74 / 74 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2 MB
```

### Implement

```Go
func rob(nums []int) int {
    if len(nums) == 1 { return nums[0] }
	prevSum := 0
	currSum := 0
	for i := 0; i < len(nums) - 1; i++ {
		temp := prevSum
		prevSum = currSum
		currSum = Max(temp + nums[i], prevSum)
	}

	result := currSum

	prevSum = 0
	currSum = 0
	for i := 1; i < len(nums); i++ {
		temp := prevSum
		prevSum = currSum
		currSum = Max(temp + nums[i], prevSum)
	}

	if currSum > result {
		result = currSum
	}

	return  result
}

func Max(x, y int) int {
	if x < y {
		return y
	}
	return x
}
```