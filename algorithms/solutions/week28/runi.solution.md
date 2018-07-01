## Problem 1
https://leetcode.com/problems/non-decreasing-array/description/

```go
func checkPossibility(nums []int) bool {
	count := 0

	for i := 1; i < len(nums); i++ {
		if count > 1 {
			return false
		}

		if nums[i-1] > nums[i] {
			count++
			if i >= 2 && nums[i-2] > nums[i] {
				nums[i] = nums[i-1]
			} else {
				nums[i-1] = nums[i]
			}
		}
	}

	return count <= 1
}
```
