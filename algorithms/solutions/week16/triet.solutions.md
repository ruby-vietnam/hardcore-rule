## Problem 1

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
