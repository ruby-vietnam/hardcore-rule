# 198

```go
func rob(nums []int) int {
    max := 0
    if len(nums) < 1 {
        return 0
    } else if len(nums) < 2 {
        max = nums[0]
    } else if len(nums) < 3 {
        if nums[0] > nums[1] {
            max = nums[0]
        } else {
            max = nums[1]
        }
    } else {
        var t []int
        t = make([]int, len(nums))
        t[0] = nums[0]
        t[1] = nums[1]
        for i := 0; i < len(nums); i++ {
            for j := 0; j < i - 1; j++ {
                if t[i] < t[j] + nums[i] {
                    t[i] = t[j] + nums[i]
                }
            }
            if t[i] > max {
                max = t[i]
            }
        }   
    }
    return max
}
```

# 139

```go 
func wordBreak(s string, wordDict []string) bool {
    r := make([]bool, len(s) + 1)
    r[0] = true
    
    for i := 1; i <= len(s); i++ {
        for j := 0; j < i; j++ {
            if r[j] && contains(s[j:i], wordDict) {
                r[i] = true
                break
            }
        }
    }
    
    return r[len(s)]
}

func contains(s string, words []string) bool {
    for _, w := range words {
        if w == s {
            return true
        }
    }
    return false
}
```

```
