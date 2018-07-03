# Problem 2

```golang
package main

import "fmt"

func permute(nums []int) [][]int {
	result := make([][]int, 0)
	size := len(nums)
	tmp := make([]int, size)
	visit := make([]bool, size)
	doPermute(&result, nums, visit, tmp, size, 0)
	return result
}

func doPermute(result *[][]int, nums []int, visit []bool, tmp []int, size int, n int) {
	if n == size {
		newPer := make([]int, size)
		for i := 0; i < size; i++ {
			newPer[i] = tmp[i]
		}
		*result = append(*result, newPer)
		return
	}
	for i := 0; i < size; i++ {
		if !visit[i] {
			visit[i] = true
			tmp[n] = nums[i]
			doPermute(result, nums, visit, tmp, size, n+1)
			visit[i] = false
		}
	}
}

func main() {
	fmt.Println(permute([]int{1, 2, 3}))
}
```