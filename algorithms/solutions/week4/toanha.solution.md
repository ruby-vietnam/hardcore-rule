## Problem 2

### Solution
Using counting sort.

```golang
package main

const MaxInt = int(^uint(0) >> 1)

func minInMap(m map[int]int) int {
	min := MaxInt
	for k, _ := range m {
		if k < min {
			min = k
		}
	}

	return min
}

func sortColors(nums []int) {
	var mapNums = map[int]int{}

	for i := 0; i < len(nums); i++ {
		mapNums[nums[i]] += 1
	}

	var min int
	for i := 0; i < len(nums); i++ {
		min = minInMap(mapNums)
		nums[i] = min

		if mapNums[min] == 1 {
			delete(mapNums, min)
		} else {
			mapNums[min] -= 1
		}
	}
}

func main() {
	var arr = []int{0, 2, 1, 2, 1, 1, 2, 0, 1, 1, 1}
	sortColors(arr)
}
```
