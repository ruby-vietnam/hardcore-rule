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

Problem 2:

https://leetcode.com/problems/find-peak-element

Cheating by return first peak instead find all.

```go
func findPeakElement(nums []int) int {
    for index, _ := range nums{ 
        if index == 0 {
            continue
        }
        if nums[index] < nums[index-1] {
            return index-1
        }
    }
    return len(nums) -1
}
```
