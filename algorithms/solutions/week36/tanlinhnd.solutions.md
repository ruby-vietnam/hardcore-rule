## Problem 1: [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/)

```go
func climbStairs(n int) int {
    if n < 3 {
        return n
    }
    
    a, b, c := 1, 2, 0
    for i := 3; i <= n; i++ {
        c = a + b
        a, b = b, c
    }
    
    return c
}
```

## Problem 2: [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

```go
func lengthOfLongestSubstring(s string) int {
    var idx, result int
    m := make([]int,256)
    
    for k, v := range s {
        if m[int(v)] != 0 {
            if m[int(v)] > idx{
                idx = m[int(v)]
            }
        }
        if k - idx + 1 > result {
            result = k - idx + 1
        }
        m[int(v)] = k + 1
    }
    
    return result
}
```
