## Problem 1


```go
func containsNearbyDuplicate(nums []int, k int) bool {
	if len(nums) == 1 {
		return false
	}
	for i := 0; i <= len(nums); i++ {
		for j := i + 1; j <= i+k; j++ {
			if j > len(nums)-1 {
				continue
			}
			if nums[i] == nums[j] {
				return true
			}
		}
	}
	return false
}
```
