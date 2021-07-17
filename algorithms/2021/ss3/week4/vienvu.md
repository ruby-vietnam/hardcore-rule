#

## Easy: two-sum

<https://leetcode.com/problems/two-sum/>

### Submission details

```
53 / 53 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 3.2 MB
```

### implement

```Go
func twoSum(nums []int, target int) []int {
	m := make(map[int] int)

	for i := 0; i < len(nums); i++ {
		j, found := m[target - nums[i]]
		if found {
			return []int{i, j}
		}
		m[nums[i]] = i
	}
	return  []int{-1, -1}
}
```

## Easy: valid-parentheses

<https://leetcode.com/problems/valid-parentheses/>

### Submission details

```
91 / 91 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.4 MB
```

### Implement

```Go
type Stack []string

func (s *Stack)isEmpty() bool  {
	return len(*s) == 0
}

func (s *Stack) Push(str string)  {
	*s = append(*s, str)
}

func (s *Stack) Pop() (string, bool)  {
	if s.isEmpty() {
		return "", false
	}

	index := len(*s) - 1
	element := (*s)[index]
	*s = (*s)[:index]

	return element, true
}

func find(slice []string, val string) bool {
	for _, item := range slice {
		if item == val { return  true }
	}

	return false
}

func isValid(s string) bool {
	sSlice := strings.Split(s, "")
	closeSlice := []string{")", "]", "}"}
	openSlice := []string{"(", "[", "{"}
	dict:= map[string]string {")" : "(", "]" : "[", "}" : "{"}
	stack := Stack([]string{})

	for _ , letter :=  range sSlice {
		if find(closeSlice, letter) && stack.isEmpty() { return  false }
		if find(openSlice, letter) {
			stack.Push(letter)
		} else {
			element, _ := stack.Pop()
			if  dict[letter] != element { return  false }
		}
	}

	if !stack.isEmpty() { return false }

	return  true
}
```

## Medium: generate-parentheses

<https://leetcode.com/problems/generate-parentheses/>

### Submission details

```
8 / 8 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.8 MB
```

### Implement

```Go
func generateParenthesis(n int) []string {
	var combinations []string
	openBracketCount := 0
	closeBracketCount := 0
	backtrack(&combinations, "", openBracketCount, closeBracketCount, n)

	return combinations
}

func backtrack(combinations *[]string, cur string, openBracketCount int, closeBracketCount int, n int)  {
	if len(cur) == n * 2 {
		*combinations = append(*combinations, cur)
		return
	}
	if openBracketCount < n {
		backtrack(combinations, cur +  "(", openBracketCount + 1, closeBracketCount, n)
	}
	if closeBracketCount < openBracketCount {
		backtrack(combinations, cur + ")", openBracketCount, closeBracketCount + 1, n)
	}
} 
```

## Medium: sum-of-two-integers

<https://leetcode.com/problems/sum-of-two-integers/>

### Submission details
13 / 13 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 1.9 MB
```
```

### Implement

```Go
func getSum(a int, b int) int {
	for b != 0 {
		carry := a & b
		a = a ^ b
		b = carry << 1
	}
	return  a
}
```
