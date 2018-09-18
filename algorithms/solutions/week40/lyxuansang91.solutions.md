# Week 40

## [Problem 1](https://leetcode.com/problems/merge-sorted-array/description/)

```go
func merge(nums1 []int, m int, nums2 []int, n int)  {
    nums3 := make([]int, m + n)
    i, j, count := 0,0,0 
    for i < m && j < n && count < m + n {
        if nums1[i] <= nums2[j] {
            nums3[count] = nums1[i]
            i++
        } else {
            nums3[count] = nums2[j]
            j++
        }
        count++
    }

    if i == m {
        for ;j < n && count < m + n; j++ {
            nums3[count] = nums2[j]
            count++
        }
    } else {
        for ;i < m && count < m + n; i++ {
            nums3[count] = nums1[i]
            count++
        }
    }
    for i := 0; i < count; i++ {
        nums1[i] = nums3[i]
    }
}
```

## [Problem 2](https://leetcode.com/problems/perfect-squares/description/)

```go
func numSquares(n int) int {
    dp := make([]int, n + 1)
    dp[0] = 0
    for i := 1; i <= n; i++ {
        dp[i] = (1 << 31) - 1
        for j := 1; j * j <= i; j++ {
            dp[i] = min(dp[i], dp[i-j*j] + 1)
        }
    }
    return dp[n]
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}

```

## [Problem 3](https://leetcode.com/problems/longest-palindromic-substring/description/)

```go
func longestPalindrome(s string) string {
    // find odd palindrome
    maxLength, sLeft, n := 0, 0, len(s)
    for i := 0; i < n; i++ {
        l,r := i, i
        for l >= 0 && r < n && s[l] == s[r] {
            if maxLength < r-l+1 {
                maxLength = r-l+1
                sLeft = l
            }
            l--
            r++
        }
    }
    // find even palindrome
    for i := 1; i < n; i++ {
        l, r := i-1, i
        for l >= 0 && r < n && s[l] == s[r] {
            if maxLength < r-l+1 {
                maxLength = r-l+1
                sLeft = l
            }
            l--
            r++
        }
    }
    
    return s[sLeft: (sLeft+maxLength)]
}
```

## [Problem 4](https://leetcode.com/problems/couples-holding-hands/description/)

```cpp
class Solution {
public:
   int minSwapsCouples(vector<int>& row) {
    int res = 0, N = row.size();
    vector<int> ptn(N, 0);
    vector<int> pos(N, 0);
    for (int i = 0; i < N; i++) {
        ptn[i] = (i % 2 == 0 ? i + 1 : i - 1);
        pos[row[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        for (int j = ptn[pos[ptn[row[i]]]]; i != j; j = ptn[pos[ptn[row[i]]]]) {
	    swap(row[i], row[j]);
            swap(pos[row[i]], pos[row[j]]);
	    res++;
	}
    }
    return res;
}
};
```