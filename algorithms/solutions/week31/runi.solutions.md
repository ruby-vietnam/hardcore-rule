## Problem 1
https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/

```go
func shortestSubarray(A []int, K int) int {
	var b = make([]int, len(A)+1)

	b[0] = 0
	for i := 1; i < len(A)+1; i++ {
		b[i] = b[i-1] + A[i-1]
	}

	minLength := len(A) + 1

	for i := 0; i < len(b)-1; i++ {
		for j := i; j < len(b); j++ {
			if b[j]-b[i] >= K {
				if j-i < minLength {
					minLength = j - i
				}
			}
		}
	}

	if minLength == len(A)+1 {
		return -1
	}

	return minLength
}
```
