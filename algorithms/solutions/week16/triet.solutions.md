## Problem 1
https://leetcode.com/problems/contains-duplicate-ii/

O(n^2)
```go
func containsNearbyDuplicate(nums []int, k int) bool {
	for i := range nums {
		for j := i + 1; j <= i+k  && j < len(nums); j++ {
			if nums[j] == nums[i] {
				return true
			}
		}
	}

	return false
}
```

O(n)
```go
func containsNearbyDuplicate(nums []int, k int) bool {
    mapNearestIndex := map[int]int{}
	for i := range nums {
		if index, exists := mapNearestIndex[nums[i]]; exists {
			if i-index <= k {
				return true
			}
		}
        mapNearestIndex[nums[i]] = i
	}
    
    return false
}
```

## Problem 2
https://leetcode.com/problems/find-peak-element/description/

O(n)
```go
func findPeakElement(nums []int) int {
    peakIndex := 0
	for i := 0; i < len(nums); i++ {
		if i-1 >= 0 {
			if nums[i] < nums[i-1] {
				continue
			}
		}

		if i+1 < len(nums) {
			if nums[i] < nums[i+1] {
				continue
			}
		}

		peakIndex = i
	}

	return peakIndex
}
```
