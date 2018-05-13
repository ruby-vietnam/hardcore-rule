## Problem 1

XOR then count number of bit `1`

```go
func hammingDistance(x int, y int) int {
  var xor uint
	xor = uint(x ^ y)
	return bits.OnesCount(xor)
}
```
