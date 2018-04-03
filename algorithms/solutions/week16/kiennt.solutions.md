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

### Approach 1
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

### Approach 2
We only need to find a peak, so we could use binary search

```go
func findPeakElement(nums []int) int {
	begin := 0
	end := len(nums) - 1
	for begin < end {
		mid := (begin + end) / 2
		if mid > 0 && nums[mid] < nums[mid-1] {
			end = mid - 1
		} else if mid < len(nums)-1 && nums[mid] < nums[mid+1] {
			begin = mid + 1
		} else {
			return mid
		}
	}
	return nums[begin]
}
```