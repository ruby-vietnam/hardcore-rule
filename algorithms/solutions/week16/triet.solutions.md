## Problem 1

O(n^2)
```go
for i := range nums {
		for j := i + 1; j < len(nums); j++ {
			if nums[j] == nums[i] && ((i-j < 0 && -(i-j) <= k) || (i-j) > 0 && (i-j) <= k) {
				return true
			}
		}
	}

return false
```
