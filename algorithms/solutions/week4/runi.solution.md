## Problem 2

### Solution
We are about to migrate all 0 to left and 2 to the right by switching the order with the next right or previous left

Code:
https://gist.github.com/RuniVN/219b9c9bebb1f12431be4631a6b9a684

```
func sortColors(nums []int) {
	i := 0
	for i < len(nums) {
		if nums[i] == 0 && i != 0 && nums[i-1] != 0 {
			nums[i], nums[i-1] = nums[i-1], nums[i]
			i--
		} else if nums[i] == 2 && i != len(nums)-1 && nums[i+1] != 2 {
			nums[i], nums[i+1] = nums[i+1], nums[i]
			if i != 0 {
				i--
			}
		} else {
			i++
		}

	}
}
```
