Problem 1:

https://leetcode.com/problems/contains-duplicate-ii

```go
func containsNearbyDuplicate(nums []int, k int) bool {
	itemsAndIndex := make(map[int]int, len(nums))
	for index, num := range nums {
		lastIndexOfDuplicatedItem, existed := itemsAndIndex[num]
		if existed && index-lastIndexOfDuplicatedItem <= k {
			return true
		} else {
			itemsAndIndex[num] = index
		}
	}
	return false
}
```
