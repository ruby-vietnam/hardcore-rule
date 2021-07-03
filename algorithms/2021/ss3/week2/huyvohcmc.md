# Easy: Happy Number

https://leetcode.com/problems/happy-number/

### Approach

The solutio is pretty straightforward: while the given number is not equals to 1, keep summing the squares of its digits and repace the number with the new sum value. There is one edge case however, that is after some iterations the sum of the squares of n's digits is exactly n and will cause the while loop to run infinitely. We need to track all the sum after each iteration to see if we've seen this sum before in order to break the infinite loop.

### Code

```go
func isHappy(n int) bool {
	seen := map[int]bool{}
	for n != 1 {
		current, sum := n, 0
		for current != 0 {
			last := current % 10
			sum += last * last
			current /= 10
		}
		if seen[sum] {
			return false
		}
		seen[sum] = true
		n = sum
	}
	return true
}
```

### Submission Detail

```
402 / 402 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.1 MB
```

# Medium: Longest Happy String

https://leetcode.com/problems/longest-happy-string/

### Code

```go
func longestDiverseString(a int, b int, c int) string {
	n := a + b + c
	str := ""
	currA, currB, currC := 0, 0, 0
	for i := 0; i < n; i++ {
		if (a >= b && a >= c && currA != 2) || (a > 0 && (currB == 2 || currC == 2)) {
			str += "a"
			currA++
			currB = 0
			currC = 0
			a--
		} else if (b >= a && b >= c && currB != 2) || (b > 0 && (currA == 2 || currC == 2)) {
			str += "b"
			currB++
			currA = 0
			currC = 0
			b--
		} else if (c >= a && c >= b && currC != 2) || (c > 0 && (currA == 2 || currB == 2)) {
			str += "c"
			currC++
			currA = 0
			currB = 0
			c--
		}
	}
	return str
}
```

Time complexity: O(n), where n = a + b + c.

### Submission Detail

```
33 / 33 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 2.3 MB
```
