# Problem 1: [Hamming Distance](https://leetcode.com/problems/hamming-distance/description/)

```go
func hammingDistance(x int, y int) int {
    if x < 0 || y < 0 {
        return 0
    }
    
    if x > 2<<30 || y > 2<<30 {
        return 0
    }
    
    distance, tmp := 0, x^y
    for tmp > 0 {
        if (tmp>>1)<<1 != tmp {
            distance++  
        }
        
        tmp>>=1
    }
    return distance
}
```
