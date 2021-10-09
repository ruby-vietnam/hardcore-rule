# Medium 1: Merge Intervals

https://leetcode.com/problems/merge-intervals/

### Code

```go
func merge(intervals [][]int) [][]int {
	if len(intervals) <= 1 {
		return intervals
	}

	sort.Slice(intervals, func (i, j int) bool { return intervals[i][0] < intervals[j][0] })
	res := [][]int{}
	for i, interval := range intervals {
		if i == 0 {
			res = append(res, interval)
			continue
		}
		curr_interval := res[len(res)-1]
		if curr_interval[1] >= interval[0] {
			res[len(res)-1] = []int{curr_interval[0], max(curr_interval[1], interval[1])}
		} else {
			res = append(res, interval)
		}
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```

### Submission Detail

```
168 / 168 test cases passed.
Status: Accepted
Runtime: 8 ms
Memory Usage: 4.8 MB
```

# Medium 2: Find First and Last Position of Element in Sorted Array

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

### Code

```go
func searchRange(nums []int, target int) []int {
	res := make([]int, 2)
	res[0] = findStartingIndex(nums, target)
	res[1] = findEndingIndex(nums, target)
	return res
}

func findStartingIndex(nums []int, target int) int {
	res := -1
	start := 0
	end := len(nums) - 1
	for start <= end {
		mid := start + (end-start)/2
		if nums[mid] >= target {
			end = mid - 1
		} else {
			start = mid + 1
		}
		if nums[mid] == target {
			res = mid
		}
	}
	return res
}

func findEndingIndex(nums []int, target int) int {
	res := -1
	start := 0
	end := len(nums) - 1
	for start <= end {
		mid := start + (end-start)/2
		if nums[mid] <= target {
			start = mid + 1
		} else {
			end = mid - 1
		}
		if nums[mid] == target {
			res = mid
		}
	}
	return res
}
```

### Submission Detail

```
88 / 88 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 4 MB
```
