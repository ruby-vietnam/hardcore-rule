## Problem 1

```go
func shiftArray(nums []int, i, lastPosition int) {
	value := nums[i]
	for j := i; j < lastPosition; j++ {
		nums[j] = nums[j+1]
	}
	nums[lastPosition] = value
}

func moveZeroes(nums []int) {
	size := len(nums)
	lastPosition := size - 1
	for i := size - 1; i >= 0; i-- {
		if nums[i] == 0 {
			shiftArray(nums, i, lastPosition)
			lastPosition--
		}
	}
}
```
