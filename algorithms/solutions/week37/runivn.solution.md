## Problem 1
https://leetcode.com/problems/power-of-three/description/

Simply satisfying by checking 3^19 mod n == 0
```go

func isPowerOfThree(n int) bool {
	return n > 0 && int64(math.Pow(3, 19))%int64(n) == 0
}
```
