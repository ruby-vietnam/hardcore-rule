Problem 1:

https://leetcode.com/problems/single-number/description/

```go
func singleNumber(nums []int) (result int) {
    for _, n := range nums {
        result ^= n
    }
    return result
}
```

Problem 2:

https://leetcode.com/problems/palindromic-substrings/description/

```go
func countSubstrings(s string) int {
    if len(s) < 2 {
        return len(s)
    }
    
    result := 0
    var left, right int 

    for i := 0; i < len(s); i++ {
        left = i
        right = i
        
        for left >= 0 && right < l && s[left] == s[right] {
            result++
            left--
            right++
        }
        
        left = i
        right = i+1
        for left >= 0 && right < l && s[left] == s[right] {
            result++
            left--
            right++
        }
    }
    
    return result
}
```
