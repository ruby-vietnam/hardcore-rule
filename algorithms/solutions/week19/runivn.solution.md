## Problem 1
https://leetcode.com/problems/hamming-distance/description/

```go
func hammingDistance(x int, y int) int {
	return bits.OnesCount(uint(x ^ y))
}

```
