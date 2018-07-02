# Problem 1: [Non-descreasing Array](https://leetcode.com/problems/non-decreasing-array/description/)

```go
func checkPossibility(nums []int) bool {
	var modified int
	for i := 1; i < len(nums) && modified <= 1; i++ {
		if nums[i-1] > nums[i] {
			modified++
			if i - 2 < 0 || nums[i-2] <= nums[i] {
				nums[i-1] = nums[i]
			} else {
				nums[i] = nums[i-1]
			}
		}
	}
	return modified <= 1
}
```
