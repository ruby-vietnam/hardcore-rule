## Problem 1

O(nLog(n))
```
func maximumProduct(nums []int) int {
	sort.Ints(nums)
	a := nums[0] * nums[1] * nums[len(nums)-1]
	b := nums[len(nums)-1] * nums[len(nums)-2] * nums[len(nums)-3]
	if a < b {
		return b
	}
	return a
}
```

O(n)
```
func maximumProductO(nums []int) int {
	var maxIndex0, maxIndex1, maxIndex2, minIndex0, minIndex1 = 0, 1, 2, 0, 1
	if nums[maxIndex0] < nums[maxIndex1] {
		maxIndex0, maxIndex1 = maxIndex1, maxIndex0
	}
	if nums[maxIndex0] < nums[maxIndex2] {
		maxIndex2, maxIndex0 = maxIndex0, maxIndex2
	}
	if nums[maxIndex1] < nums[maxIndex2] {
		maxIndex2, maxIndex1 = maxIndex1, maxIndex2
	}
	/*for i, num := range nums {
		if num > nums[maxIndex0] {
			maxIndex0 = i
		}
	}*/
	maxIndex0 = findMax(nums, maxIndex0, -1, -1)
	maxIndex1 = findMax(nums, maxIndex1, maxIndex0, -1)
	maxIndex2 = findMax(nums, maxIndex2, maxIndex0, maxIndex1)
	if nums[minIndex0] > nums[minIndex1] {
		minIndex0, minIndex1 = minIndex1, minIndex0
	}
	for i, num := range nums {
		if num < nums[minIndex0] {
			minIndex0 = i
		}
	}
	minIndex1 = findMin(nums, minIndex1, minIndex0)
	fmt.Println(maxIndex0, maxIndex1, maxIndex2, minIndex0, minIndex1)

	a := nums[maxIndex0] * nums[minIndex1] * nums[minIndex0]
	b := nums[maxIndex0] * nums[maxIndex1] * nums[maxIndex2]
	if a < b {
		return b
	}
	return a

}

func findMin(nums []int, init, minIndex1 int) int {
	minIndex := init
	for i, num := range nums {
		if num < nums[minIndex] && num >= nums[minIndex1] && i != minIndex1 {
			minIndex = i
		}
	}
	return minIndex
}

func findMax(nums []int, init, maxIndex1, maxIndex2 int) int {
	maxIndex := init
	for i, num := range nums {
		if num > nums[maxIndex] {
			if maxIndex1 >= 0 && (i == maxIndex1 || num > nums[maxIndex1]) {
				continue
			}

			if maxIndex2 >= 0 && (i == maxIndex2 || num > nums[maxIndex2]) {
				continue
			}
			maxIndex = i
		}
	}
	return maxIndex
}
```
