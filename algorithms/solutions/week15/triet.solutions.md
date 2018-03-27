## Problem 1
https://leetcode.com/problems/move-zeroes/

```go
func moveZeroes(nums []int) {
	if len(nums) <= 1 {
		return
	}
	countZ := 0

	i := 0
	for i < len(nums) {
		// 0 1 0 3 12
		if nums[i] == 0 {
			countZ++
			i++
			continue
		}
		nums[i-countZ] = nums[i]
		i++
	}

	// Replace countZ = 0
	for i := 0; i < countZ; i++ {
		nums[len(nums)-i-1] = 0
	}
}
```
