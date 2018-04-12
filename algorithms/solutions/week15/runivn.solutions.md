## Problem 1

```go
func moveZeroes(nums []int) {
	firstZero := 0
	for i := range nums {
		if nums[i] != 0 {
			nums[i], nums[firstZero] = nums[firstZero], nums[i]
			firstZero++
		}
	}
}
```
