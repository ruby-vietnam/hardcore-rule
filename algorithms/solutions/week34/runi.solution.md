## Problem 1
https://leetcode.com/problems/house-robber

```go

func rob(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	if len(nums) == 1 {
		return nums[0]
	}

	var m = make([]int, len(nums))
	m[0] = nums[0]
	m[1] = nums[1]
	if nums[0] > nums[1] {
		m[1] = nums[0]
	}

	for i := 2; i < len(nums); i++ {
		m[i] = m[i-1]

		if nums[i]+m[i-2] > m[i-1] {
			m[i] = nums[i] + m[i-2]
		}
	}

	return m[len(nums)-1]
}
```
