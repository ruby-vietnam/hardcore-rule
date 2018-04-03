## Problem 1

```go
func containsNearbyDuplicate(nums []int, k int) bool {
	indexes := make(map[int]int)
	for i, value := range nums {
		lastIndex, ok := indexes[value]
		if ok && i-lastIndex <= k {
			return true
		}
		indexes[value] = i
	}
	return false
}
```

## Problem 2

The maxinum number is a peak -> find maximum

```go
func findPeakElement(nums []int) int {
    if len(nums) == 0 {
        return -1
    }
    index := 0
    max := nums[0]
    for i := 1; i < len(nums); i++ {
        if nums[i] > max {
            index = i
            max = nums[i]
        }
    }
    return index
}
```