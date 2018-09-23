Problem 1:

https://leetcode.com/problems/merge-sorted-array/description/

```go
func merge(nums1 []int, m int, nums2 []int, n int) {
	if n == 0 {
		return
	}
	if m == 0 {
        copy(nums1, nums2)
		return
	}
	pushDataBack(nums1, m, n)
	for im, in, i := n, 0, 0; (im < m+n || in < n) && i < m+n; i++ {
		if (im < m+n && in >= n) || (im < m+n && nums1[im] < nums2[in]) {
			nums1[i] = nums1[im]
			im++
		} else if in < n {
			nums1[i] = nums2[in]
			in++
		} else {
			break
		}
	}
}

func pushDataBack(nums []int, m, n int) {
	for i := m - 1; i >= 0; i-- {
		nums[i+n] = nums[i]
	}
}

```

Problem 2:

https://leetcode.com/problems/perfect-squares/description/

```go
func numSquares(n int) int {
	dp := make([]int, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = 999999999
	}
	dp[0] = 0
	for i := 0; i <= n; i++ {

		for j := 1; i+j*j <= n; j++ {
			dp[i+j*j] = min(dp[i+j*j], dp[i]+1)

		}
	}
	return dp[n]
}

func min(m, n int) int {
	if m < n {
		return m
	}
	return n
}
```

Problem 3:

https://leetcode.com/problems/longest-palindromic-substring/description/

```go
func longestPalindrome(s string) string {
    strLen := len(s)
    if strLen <= 1 {
        return s
    }
    
    dp := make([][]bool, strLen + 1)
    for idx, _ := range dp {
        dp[idx] = make([]bool, strLen + 1)
        dp[idx][idx] = true
        if idx != strLen {
            dp[idx][idx + 1] = true
        }
    }

    i, j := -1, -1
    for gap := 2; gap <= strLen; gap++ {
        for start := 0; start <= strLen - gap; start++ {
            end := start + gap - 1
            isPalindrome := (s[start] == s[end]) && dp[start + 1][start + gap - 1]
            dp[start][start + gap] = isPalindrome
            if isPalindrome {
                i, j = start, start + gap
            }
        }
    }
    
    if i != -1 && j != -1 {
        return s[i:j]
    } else {
        return s[0:1]
    }
}
```
