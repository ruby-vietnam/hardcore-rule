Problem 1:

https://leetcode.com/problems/hamming-distance

Boring:
```go
func hammingDistance(x int, y int) int {
    return bits.OnesCount(uint(x^y))
}
```

Unboring:
```go
func hammingDistance(x int, y int) int {
	z := uint(x^y)
	base := uint(1)
	count := 0
	for i := uint(0); i < 32; i++ {
		n := base << i
		if z & n == n {
			count++
		}
	}
	return count
}
```
