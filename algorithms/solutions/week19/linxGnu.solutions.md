## Problem 1 - [Hamming Distance](https://leetcode.com/problems/hamming-distance/description/)

```go
func hammingDistance(x int, y int) int {
    x = x ^ y
    
    count := 0
    for x > 0 {
        count++
        if y = x & (x-1); y == 0 {
            return count
        }
        x = y
    }
    
    return count
}
```