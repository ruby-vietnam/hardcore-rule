## Problem 1 - [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/description/)

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        while(n>0)A[m+n-1]=(m==0||B[n-1]>A[m-1])?B[--n]:A[--m];
    }
}
```

## Problem 2 - [Perfect Squares](https://leetcode.com/problems/perfect-squares/description/)

```go
func numSquares(n int) int {
    f := make([]int, n + 1)
    f[0], f[1] = 0, 1
    
    var tmp int
    for i := 2; i <= n; i++ {
        f[i] = i
        for j := 1; j <= i; j++ {
            tmp = i - j * j
            if tmp < 0 {
                break
            }
            
            if f[i] > f[tmp] + 1 {
                f[i] = f[tmp] + 1
            }
        }
    }
    
    return f[n]
}
```

## Problem 3 - [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/description/)

```go
func expandPString(s []byte, left, right int) (int, int) {
    lenS := len(s)
    
    if s[left] != s[right] {
        return left, left
    }
    
    for left > 0 && right < lenS - 1 && s[left - 1] == s[right + 1] {
        left--
        right++
    }
    
    return left, right
}

func longestPalindrome(_s string) string {
    s := []byte(_s)    
    
    lenS := len(s)
    if lenS == 0 {
        return ""
    }
    
    l1, r1, max := 0, 0, 0
    for i := range s {
        left, right := expandPString(s, i, i)
        if right - left > max {
            max = right - left
            l1, r1 = left, right
        }
        
        if i + 1 < lenS {
            left, right = expandPString(s, i, i+1)
            if right - left > max {
              max = right - left
              l1, r1 = left, right
            }
        }
    }
    
    return _s[l1:r1+1]
}
```
