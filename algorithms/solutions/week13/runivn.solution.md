## Problem 1

https://leetcode.com/problems/maximum-product-of-three-numbers/description/

Just sort and find 3 biggest numbers and 2 smallest numbers then compare the product

```go
func maximumProduct(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	if len(nums) == 1 {
		return nums[0]
	}

	if len(nums) == 2 {
		return nums[0] * nums[1]
	}

	sort.Slice(nums, func(i, j int) bool {
		return nums[i] > nums[j]
	})

	if nums[len(nums)-1]*nums[len(nums)-2]*nums[0] > nums[0]*nums[1]*nums[2] {
		return nums[len(nums)-1] * nums[len(nums)-2] * nums[0]
	}

	return nums[0] * nums[1] * nums[2]
}
```
