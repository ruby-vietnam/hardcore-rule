# non-decreasing-array

```go
package main

import "fmt"

func checkPossibility(nums []int) bool {
	var index = -1

	for i := 0; i < len(nums)-1; i++ {
		if nums[i] > nums[i+1] {
			if index != -1 {
				return false
			}
			index = i
		}
	}

	return index == -1 ||
		index == 0 ||
		index == len(nums)-2 ||
		nums[index-1] <= nums[index+1] ||
		nums[index] <= nums[index+2]
}

func main() {
	fmt.Println(checkPossibility([]int{4, 2, 1}) == false)
}
```