## Problem 1 - [Reverse Integer](https://leetcode.com/problems/reverse-integer/description/)

```go
func reverse(x int) int {
    if x == 0 {
        return 0
    }
    
    isMinus := x < 0
    if x < 0 {
        x = -x
    }
    
    a := make([]int, 32)
    n := 0
    for x > 0 {
        a[n] = x % 10
        n++
        x = x / 10
    }
    
    res := 0
    pow := 1
    for i := n - 1;i >= 0;i-- {
        res += a[i] * pow
        pow *= 10
    }
    if isMinus {
        res = -res
    }
    
    minInt, maxInt := -2147483648, 2147483647
    if res > maxInt || res < minInt {
        return 0
    }
    
    return res
}
```

## Problem 3 - [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/description/)

```go
func checkSubarraySum(nums []int, k int) bool {
    if k < 0 {
        k = -k
    }
    
    m := make(map[int]int)

    var mod int
    for i := range nums {
        if i > 0 {
            nums[i] += nums[i-1]
        }
        
        if k > 0 {
            mod = nums[i] % k
        } else {
            mod = nums[i]
        }
        
        if mod == 0 && i > 0 {
            return true
        }
        
        if ind, ok := m[mod]; ok {
            if i - ind > 1 {
                return true
            }
        } else {
            m[mod] = i
        }
    }
    
    return false
}
```