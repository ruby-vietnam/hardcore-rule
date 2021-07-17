# Easy 1: Two Sum

https://leetcode.com/problems/two-sum/

### Approach

Loop through the input and building a hashmap for each number with the key being `target-num` and the value being num index. That way, when we check a number in the input, we can check if that number exists in the hashmap first and returns the result.

### Code

```go
func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for i, num := range nums {
		if _, ok := m[num]; ok {
			return []int{i, m[num]}
		} else {
			m[target-num] = i
		}
	}
	return nil
}
```

Time complexity: O(n), space complexity: O(n).

### Submission Detail

```
54 / 54 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 4.3 MB
```

# Easy 2: Valid Parentheses

https://leetcode.com/problems/valid-parentheses/

### Approach

We can solve this problem using a stack and a hashmap. First we create the hashmap to map closed brackets to its open brackets. Then we iterate through each bracket from the input:
- If the bracket is a closed bracket, and the stack is empty -> invalid string.
- If the bracket is a closed bracket, and the last bracket in the stack is not the same type with the current one -> invalid string.
- If the bracket is a closed bracket, and the last bracket in the stack is the same type with the current one -> pop an element from the stack, continue iterating the input.
- Else, the bracket is an open bracket -> push it to the stack.

### Code

```go
func isValid(s string) bool {
	stack := []string{}
	mapping := map[string]string{")": "(", "]": "[", "}": "{"}

	for _, c := range s {
		curr := string(c)
		if _, ok := mapping[curr]; ok {
			if len(stack) == 0 {
				return false
			}
			end := len(stack) - 1
			top := stack[end]
			if mapping[curr] != top {
				return false
			} else {
				stack = stack[:end]
			}
		} else {
			stack = append(stack, curr)
		}
	}

	if len(stack) > 0 {
		return false
	}
	return true
}
```

Time complexity: O(n), space complexity: O(n).

### Submission Detail

```
91 / 91 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.2 MB
```

# Medium: Generate Parentheses

https://leetcode.com/problems/generate-parentheses/

### Code

```go
func generateParenthesis(n int) []string {
	res := []string{}
	curr := []byte{}
	backtrack(&res, curr, 0, 0, n)
	return res
}

func backtrack(res *[]string, curr []byte, open, close, max int) {
	if len(curr) == max*2 {
		*res = append(*res, string(curr))
		return
	}
	if open < max {
		backtrack(res, append(curr, '('), open+1, close, max)
	}
	if close < open {
		backtrack(res, append(curr, ')'), open, close+1, max)
	}
}
```

### Submission Detail:

```
8 / 8 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.7 MB
```
