# Problem 1: (House Robber)[https://leetcode.com/problems/house-robber/description/]

```go
func rob(nums []int) int {
    numHouse := len(nums)
    if numHouse == 0 {
        return 0
    }
    if numHouse == 1 {
        return nums[0]
    }
    
    n := nums[0]
    m := max(nums[0], nums[1])
    for i := 2; i < len(nums); i++ {
        curr := max(n + nums[i], m)
        n = m
        m = curr
    }
    if n < m {
        return m
    }
    return n
}
```

# Problem 2: (Word Break)[https://leetcode.com/problems/word-break/description/]

```go
func wordBreak(s string, wordDict []string) bool {
    dict := make(map[string]bool)
    for _, str := range wordDict {
        dict[str] = true
    }
    
    boolArr := make([]bool, len(s) + 1)
    boolArr[0] = true
    for i := 1; i < len(boolArr); i++ {
        for j := i-1; j >= 0; j-- {
            if boolArr[j] && dict[s[j:i]] {
                boolArr[i] = true
            }
        }
    }
    return boolArr[len(s)]
}
```
